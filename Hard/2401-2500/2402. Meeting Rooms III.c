// 2402. Meeting Rooms III
// 
// You are given an integer n. There are n rooms numbered from 0 to n - 1.
// 
// You are given a 2D integer array meetings where meetings[i] = [starti, endi] means 
// that a meeting will be held during the half-closed time interval [starti, endi). All the 
// values of starti are unique.
// 
// Meetings are allocated to rooms in the following manner:
// 
// Each meeting will take place in the unused room with the lowest number.
// If there are no available rooms, the meeting will be delayed until a room becomes free. 
// The delayed meeting should have the same duration as the original meeting.
// When a room becomes unused, meetings that have an earlier original start time should 
// be given the room.
// 
// Return the number of the room that held the most meetings. If there are multiple rooms, 
// return the room with the lowest number.
// 
// A half-closed interval [a, b) is the interval between a and b including a and not 
// including b.
// 
// Example 1:
// 
// Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
// Output: 0
// Explanation:
// - At time 0, both rooms are not being used. The first meeting 
// starts in room 0.
// - At time 1, only room 1 is not being used. The second meeting 
// starts in room 1.
// - At time 2, both rooms are being used. The third meeting is 
// delayed.
// - At time 3, both rooms are being used. The fourth meeting is 
// delayed.
// - At time 5, the meeting in room 1 finishes. The third meeting 
// starts in room 1 for the time period [5,10).
// - At time 10, the meetings in both rooms finish. The fourth 
// meeting starts in room 0 for the time period [10,11).
// Both rooms 0 and 1 held 2 meetings, so we return 0. 
// 
// Example 2:
// Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
// Output: 1
// Explanation:
// - At time 1, all three rooms are not being used. The first 
// meeting starts in room 0.
// - At time 2, rooms 1 and 2 are not being used. The second meeting 
// starts in room 1.
// - At time 3, only room 2 is not being used. The third meeting 
// starts in room 2.
// - At time 4, all three rooms are being used. The fourth meeting 
// is delayed.
// - At time 5, the meeting in room 2 finishes. The fourth meeting 
// starts in room 2 for the time period [5,10).
// - At time 6, all three rooms are being used. The fifth meeting is 
// delayed.
// - At time 10, the meetings in rooms 1 and 2 finish. The fifth 
// meeting starts in room 1 for the time period [10,12).
// Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, 
// so we return 1. 
// 
// Constraints:
// 
// 1 <= n <= 100
// 1 <= meetings.length <= 10^5
// meetings[i].length == 2
// 0 <= starti < endi <= 5 * 10^5
// All the values of starti are unique.

#include <stdlib.h>     // qsort, malloc, free
#include <stddef.h>     // size_t

struct Meeting {
    int start;
    int end;
};

struct BusyItem {
    long long endTime;
    int roomId;
};

static int compareMeetingByStart(const void *a, const void *b){
    const struct Meeting *ma;
    const struct Meeting *mb;
    ma = (const struct Meeting *)a;
    mb = (const struct Meeting *)b;
    if (ma->start < mb->start) return -1;
    if (ma->start > mb->start) return 1;
    return 0;
}

static int busyLess(const struct BusyItem *a, const struct BusyItem *b){
    if (a->endTime < b->endTime) return 1;
    if (a->endTime > b->endTime) return 0;
    return (a->roomId < b->roomId) ? 1 : 0;
}

static void busySwap(struct BusyItem *a, struct BusyItem *b){
    struct BusyItem tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

static void busyHeapPush(struct BusyItem *heap, int *heapSize, struct BusyItem item){
    int idx;
    int parent;
    idx = *heapSize; 
    heap[idx] = item; 
    *heapSize = *heapSize + 1; 
    
    while (idx > 0){
        parent = (idx - 1) / 2; 
        if (busyLess(&heap[parent], &heap[idx])) break; 
        busySwap(&heap[parent], &heap[idx]); 
        idx = parent; 
    }
}

static struct BusyItem busyHeapPop(struct BusyItem *heap, int *heapSize){
    struct BusyItem top;
    int idx;
    int left;
    int right;
    int smallest;

    top = heap[0];
    *heapSize = *heapSize - 1;
    heap[0] = heap[*heapSize];

    idx = 0;
    while (1){
        left = idx * 2 + 1;
        right = idx * 2 + 2;
        smallest = idx;

        if (left < *heapSize && busyLess(&heap[left], &heap[smallest])){
            smallest = left;
        }
        if (right < *heapSize && busyLess(&heap[right], &heap[smallest])){
            smallest = right;
        }
        if (smallest == idx) break;
        busySwap(&heap[idx], &heap[smallest]);
        idx = smallest;
    }
    return top;
}

static struct BusyItem busyHeapTop(const struct BusyItem *heap){
    return heap[0];
}

static int findLowestFreeRoom(const char *used, int n){
    int room;
    for (room = 0; room < n; room++) {
        if (!used[room]) return room;
    }
    return -1;
}

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize){
    struct Meeting *sortedMeetings;
    struct BusyItem *busyHeap;

    char *used;
    int *meetingCount;

    int i;
    int heapSize;

    int bestRoom;
    int bestCount;

    if (n <= 0 || meetings == NULL || meetingsSize <= 0 || meetingsColSize == NULL) return 0;

    sortedMeetings = (struct Meeting *)malloc((size_t)meetingsSize * sizeof(struct Meeting));
    busyHeap = (struct BusyItem *)malloc((size_t)n * sizeof(struct BusyItem));
    used = (char *)malloc((size_t)n * sizeof(char));
    meetingCount = (int *)malloc((size_t)n * sizeof(int));

    if (sortedMeetings == NULL || busyHeap == NULL || used == NULL || meetingCount == NULL){
        free(sortedMeetings);
        free(busyHeap);
        free(used);
        free(meetingCount);
        return 0;
    }

    for (i = 0; i < meetingsSize; i++){
        sortedMeetings[i].start = meetings[i][0];
        sortedMeetings[i].end = meetings[i][1];
    }

    qsort(sortedMeetings, (size_t)meetingsSize, sizeof(struct Meeting), compareMeetingByStart);

    for (i = 0; i < n; i++){
        used[i] = 0;
        meetingCount[i] = 0;
    }
    heapSize = 0;

    for (i = 0; i < meetingsSize; i++){
        long long startTime;
        long long endTime;
        long long duration;

        int room;
        struct BusyItem topBusy;
        struct BusyItem newBusy;

        startTime = (long long)sortedMeetings[i].start;
        endTime = (long long)sortedMeetings[i].end;
        duration = endTime - startTime;

        // free rooms whose meetings ended by startTime (half-open: end <= start is free)
        while (heapSize > 0) {
            topBusy = busyHeapTop(busyHeap);
            if (topBusy.endTime > startTime) break;

            topBusy = busyHeapPop(busyHeap, &heapSize);
            used[topBusy.roomId] = 0;
        }

        room = findLowestFreeRoom(used, n);

        if (room >= 0){
            // schedule immediately
            used[room] = 1;
            meetingCount[room]++;

            newBusy.endTime = endTime;
            newBusy.roomId = room;
            busyHeapPush(busyHeap, &heapSize, newBusy);
        } else {
            // delay: take earliest finishing room
            topBusy = busyHeapPop(busyHeap, &heapSize);
            room = topBusy.roomId;

            meetingCount[room]++;

            newBusy.endTime = topBusy.endTime + duration;
            newBusy.roomId = room;
            busyHeapPush(busyHeap, &heapSize, newBusy);

            // used[room] remains 1 (still busy)
        }
    }

    bestRoom = 0;
    bestCount = meetingCount[0];
    for (i = 1; i < n; i++) {
        if (meetingCount[i] > bestCount) {
            bestCount = meetingCount[i];
            bestRoom = i;
        }
    }
    free(sortedMeetings);
    free(busyHeap);
    free(used);
    free(meetingCount);
    return bestRoom;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
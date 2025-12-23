// 2054. Two Best Non-Overlapping Events
//
// You are given a 0-indexed 2D integer array of events where 
// events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and 
// ends at endTimei, and if you attend this event, you will receive a value of valuei. 
// You can choose at most two non-overlapping events to attend such that the sum of their 
// values is maximized.
// 
// Return this maximum sum.
// 
// Note that the start time and end time is inclusive: that is, you cannot attend 
// two events where one of them starts and the other ends at the same time. More 
// specifically, if you attend an event with end time t, the next event must start 
// at or after t + 1.
//  
// 
// Example 1:
// Time:    1 2 3 4 5
//          | | | | |
// Event 0: = = = - -   value = 2   [1..3]
// Event 1: - - - = =   value = 2   [4..5]
// Event 2: - # # # -   value = 3   [2..4]
// 
// Chosen: Event 0 + Event 1
// Sum = 2 + 2 = 4
// 
// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4
// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
// 
// Example 2:
// Time:    1 2 3 4 5
//          | | | | |
// Event 0: # # # - -   value = 2   [1..3]
// Event 1: - - - # #   value = 2   [4..5]
// Event 2: = = = = =   value = 5   [1..5]
// 
// Chosen: Event 2
// Sum = 5
//
// Input: events = [[1,3,2],[4,5,2],[1,5,5]]
// Output: 5
// Explanation: Choose event 2 for a sum of 5.
// 
// Example 3:
// Time:    1 2 3 4 5 6
//          | | | | | |
// Event 0: = = = = = -   value = 3   [1..5]
// Event 1: # # # # # -   value = 1   [1..5]
// Event 2: - - - - - =   value = 5   [6..6]
// 
// Chosen: Event 0 + Event 2
// Sum = 3 + 5 = 8
// 
// Input: events = [[1,5,3],[1,5,1],[6,6,5]]
// Output: 8
// Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
//  
// 
// Constraints:
// 
// 2 <= events.length <= 10^5
// events[i].length == 3
// 1 <= startTimei <= endTimei <= 10^9
// 1 <= valuei <= 10^6

#include <stdlib.h>         // qsort, malloc, free
#include <stddef.h>         // size_t

struct Event {
    int start;
    int end;
    int value;
};

static int compareEventByStart(const void *a, const void *b){
    const struct Event *ea;
    const struct Event *eb;
    ea = (const struct Event *)a;
    eb = (const struct Event *)b;
    if (ea->start < eb->start) return -1;
    if (ea->start > eb->start) return 1;
    if (ea->end < eb->end) return -1;
    if (ea->end > eb->end) return 1;
    if (ea->value < eb->value) return -1;
    if (ea->value > eb->value) return 1;
    return 0;
}

static int lowerBoundStart(const int *starts, int n, int target){
    int left, mid, right;
    left = 0;
    right = n;
    while (left < right){
        mid = left + (right - left) / 2;
        if (starts[mid] < target){
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize){
    struct Event *sortedEvents;
    int *starts;
    int *suffixMaxValue;
    int i;
    int bestSingle;
    int bestTotal;
    if (events == NULL || eventsSize <= 0 || eventsColSize == NULL) return 0;
    sortedEvents = (struct Event *)malloc((size_t)eventsSize * sizeof(struct Event));
    starts = (int *)malloc((size_t)eventsSize * sizeof(int));
    suffixMaxValue = (int *)malloc((size_t)eventsSize * sizeof(int));
    if (sortedEvents == NULL || starts == NULL || suffixMaxValue == NULL){
        free(sortedEvents);
        free(starts);
        free(suffixMaxValue);
        return 0;
    }
    for (i = 0; i < eventsSize; i++){
        sortedEvents[i].start = events[i][0];
        sortedEvents[i].end = events[i][1];
        sortedEvents[i].value = events[i][2];
    }
    qsort(
            sortedEvents, 
            (size_t)eventsSize, 
            sizeof(struct Event), 
            compareEventByStart
        );
    for ( i = 0; i < eventsSize; i++){
        starts[i] = sortedEvents[i].start;
    }
    suffixMaxValue[eventsSize - 1] = sortedEvents[eventsSize - 1].value;
    for (i = eventsSize - 2; i >= 0; i--){
        int v;
        v = sortedEvents[i].value;
        suffixMaxValue[i] = (suffixMaxValue[i + 1] > v) ? 
                suffixMaxValue[i + 1] : v;
    }
    bestSingle = 0;
    bestTotal = 0;

    for (i = 0; i < eventsSize; i++) {
        int valueFirst;
        int nextStartNeed;
        int j;
        int candidate;
        valueFirst = sortedEvents[i].value;
        if (valueFirst > bestSingle) bestSingle = valueFirst;
        nextStartNeed = sortedEvents[i].end + 1;
        j = lowerBoundStart(starts, eventsSize, nextStartNeed);
        candidate = valueFirst;
        if (j < eventsSize) candidate += suffixMaxValue[j];
        if (candidate > bestTotal) bestTotal = candidate;
    }
    if (bestSingle > bestTotal) bestTotal = bestSingle;
    free(sortedEvents);
    free(starts);
    free(suffixMaxValue);
    return bestTotal;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
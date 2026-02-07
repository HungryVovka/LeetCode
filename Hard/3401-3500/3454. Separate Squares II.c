// 3454. Separate Squares II
//
// You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] 
// represents the coordinates of the bottom-left point and the side length 
// of a square parallel to the x-axis.
// 
// Find the minimum y-coordinate value of a horizontal line such that the 
// total area covered by squares above the line equals the total area 
// covered by squares below the line.
// 
// Answers within 10-5 of the actual answer will be accepted.
// 
// Note: Squares may overlap. Overlapping areas should be counted only 
// once in this version.
// 
// 
// Example 1:
// 
// Input: squares = [[0,0,1],[2,2,1]]
// 
// Output: 1.00000
// 
// Explanation:
// 
// y
// 4 |
// 3 |        ### 
// 2 |        ###
// 1 |----------------------  y = 1
// 0 | ### 
//   | ### 
//   +-----------------------
//     0   1   2   3   4     x
// 
// Any horizontal line between y = 1 and y = 2 results in an equal split, 
// with 1 square unit above and 1 square unit below. The minimum y-value is 1.
// 
// Example 2:
// 
// Input: squares = [[0,0,2],[1,1,1]]
// 
// Output: 1.00000
// 
// Explanation:
// 
// y
// 4 |
// 3 |
// 2 | ### ### 
// 1 |----------------------  y = 1
// 0 | ### ### 
//   +-----------------------
//     0   1   2   3   4     x
// 
// Since the blue square overlaps with the red square, it will not be counted again. 
// Thus, the line y = 1 splits the squares into two equal parts.
// 
// 
// Constraints:
// 
// 1 <= squares.length <= 5 * 10^4
// squares[i] = [xi, yi, li]
// squares[i].length == 3
// 0 <= xi, yi <= 10^9
// 1 <= li <= 10^9
// The total area of all the squares will not exceed 10^15.

#include <stdlib.h>     // malloc, free, qsort
#include <stddef.h>     // size_t

struct Event {
    long long y;
    int type;           // +1 add, -1 remove
    long long x1;
    long long x2;       // [x1, x2)
};

static int cmpLL(const void *a, const void *b) {
    long long x, y;
    x = *(const long long *)a;
    y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static int cmpEvent(const void *a, const void *b) {
    const struct Event *ea;
    const struct Event *eb;
    ea = (const struct Event *)a;
    eb = (const struct Event *)b;
    if (ea->y < eb->y) return -1;
    if (ea->y > eb->y) return 1;
    // tie-break not strictly required, but stable behavior is fine 
    if (ea->type > eb->type) return -1; // add before remove
    if (ea->type < eb->type) return 1;
    if (ea->x1 < eb->x1) return -1;
    if (ea->x1 > eb->x1) return 1;
    if (ea->x2 < eb->x2) return -1;
    if (ea->x2 > eb->x2) return 1;
    return 0;
}

// segment tree for union length on x-intervals between xs[i]..xs[i+1] 
struct SegTree {
    int nSeg;               // number of elementary segments = m-1
    long long *xs;          // coordinates array length m
    int *cover;             // cover count
    long long *len;         // covered length
};

static void segPull(struct SegTree *st, int node, int left, int right) {
    if (st->cover[node] > 0) {
        st->len[node] = st->xs[right + 1] - st->xs[left];
        return;
    }
    if (left == right) {
        st->len[node] = 0;
        return;
    }
    st->len[node] = st->len[node * 2] + st->len[node * 2 + 1];
}

static void segUpdate(struct SegTree *st, int node, int left, int right, int ql, int qr, int delta) {
    int mid;
    if (qr < left || right < ql) return;
    if (ql <= left && right <= qr) {
        st->cover[node] += delta;
        segPull(st, node, left, right);
        return;
    }
    mid = left + (right - left) / 2;
    segUpdate(st, node * 2, left, mid, ql, qr, delta);
    segUpdate(st, node * 2 + 1, mid + 1, right, ql, qr, delta);
    segPull(st, node, left, right);
}

static int lowerBoundLL(const long long *arr, int n, long long target) {
    int l, r, m;
    l = 0;
    r = n;
    while (l < r) {
        m = l + (r - l) / 2;
        if (arr[m] < target) l = m + 1;
        else r = m;
    }
    return l;
}

static long double sweepTotalArea(struct Event *ev, int evN, struct SegTree *st) {
    int i;
    long long prevY;
    long double area;
    long long curLen;
    int mSeg;
    if (evN == 0 || st->nSeg <= 0) return 0.0L;
    i = 0;
    prevY = ev[0].y;
    area = 0.0L;
    mSeg = st->nSeg;
    while (i < evN) {
        long long y;
        long long dy;
        y = ev[i].y;
        dy = y - prevY;
        curLen = st->len[1];
        if (dy > 0 && curLen > 0) {
            area += (long double)curLen * (long double)dy;
        }
        // process all events at y 
        while (i < evN && ev[i].y == y) {
            int l, r;
            l = lowerBoundLL(st->xs, mSeg + 1, ev[i].x1);
            r = lowerBoundLL(st->xs, mSeg + 1, ev[i].x2);
            if (l < r) {
                // segments are [0..nSeg-1], so update [l..r-1] 
                segUpdate(st, 1, 0, mSeg - 1, l, r - 1, ev[i].type);
            }
            i++;
        }
        prevY = y;
    }
    return area;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    struct Event *events;
    long long *xs;
    int evN;
    int xN;
    int i;
    int m;
    int segN;
    struct SegTree st;
    long double totalArea;
    long double halfArea;
    // second sweep variables 
    long long prevY;
    int idx;
    long double acc;
    double answer;
    if (squares == NULL || squaresSize <= 0 || squaresColSize == NULL) return 0.0;
    evN = squaresSize * 2;
    events = (struct Event *)malloc((size_t)evN * sizeof(struct Event));
    xs = (long long *)malloc((size_t)evN * sizeof(long long));
    if (events == NULL || xs == NULL) {
        free(events);
        free(xs);
        return 0.0;
    }
    // build events and x coords
    for (i = 0; i < squaresSize; i++) {
        long long x, y, l;
        long long x1, x2, y1, y2;
        x = (long long)squares[i][0];
        y = (long long)squares[i][1];
        l = (long long)squares[i][2];
        x1 = x;
        x2 = x + l;
        y1 = y;
        y2 = y + l;
        events[2 * i].y = y1;
        events[2 * i].type = +1;
        events[2 * i].x1 = x1;
        events[2 * i].x2 = x2;
        events[2 * i + 1].y = y2;
        events[2 * i + 1].type = -1;
        events[2 * i + 1].x1 = x1;
        events[2 * i + 1].x2 = x2;
        xs[2 * i] = x1;
        xs[2 * i + 1] = x2;
    }
    qsort(events, (size_t)evN, sizeof(struct Event), cmpEvent);
    qsort(xs, (size_t)evN, sizeof(long long), cmpLL);
    // unique xs
    xN = 0;
    for (i = 0; i < evN; i++) {
        if (i == 0 || xs[i] != xs[i - 1]) {
            xs[xN] = xs[i];
            xN++;
        }
    }
    // need at least 2 distinct x to form segments
    if (xN < 2) {
        // all squares have zero width? impossible since l>=1, but keep safe
        free(events);
        free(xs);
        return (double)events[0].y;
    }
    segN = xN - 1;
    st.nSeg = segN;
    st.xs = xs;
    st.cover = (int *)malloc((size_t)(segN * 4 + 5) * sizeof(int));
    st.len = (long long *)malloc((size_t)(segN * 4 + 5) * sizeof(long long));
    if (st.cover == NULL || st.len == NULL) {
        free(events);
        free(xs);
        free(st.cover);
        free(st.len);
        return 0.0;
    }
    // init segtree arrays 
    for (i = 0; i < segN * 4 + 5; i++) {
        st.cover[i] = 0;
        st.len[i] = 0;
    }
    // 1) total area
    totalArea = sweepTotalArea(events, evN, &st);
    halfArea = totalArea / 2.0L;
    // reset segtree for 2nd sweep
    for (i = 0; i < segN * 4 + 5; i++) {
        st.cover[i] = 0;
        st.len[i] = 0;
    }
    // 2) find minimal y where area below reaches half 
    prevY = events[0].y;
    idx = 0;
    acc = 0.0L;
    answer = (double)prevY;
    while (idx < evN) {
        long long y;
        long long dy;
        long long curLen;
        long double slabArea;
        y = events[idx].y;
        dy = y - prevY;
        curLen = st.len[1];
        if (dy > 0 && curLen > 0) {
            slabArea = (long double)curLen * (long double)dy;
            if (acc + slabArea >= halfArea) {
                long double need;
                long double fracY;

                need = halfArea - acc;                 // area still needed in this slab 
                fracY = (long double)prevY + need / (long double)curLen;
                answer = (double)fracY;
                break;
            }
            acc += slabArea;
        }
        // apply all events at y 
        while (idx < evN && events[idx].y == y) {
            int l, r;
            l = lowerBoundLL(st.xs, xN, events[idx].x1);
            r = lowerBoundLL(st.xs, xN, events[idx].x2);
            if (l < r) {
                segUpdate(&st, 1, 0, segN - 1, l, r - 1, events[idx].type);
            }
            idx++;
        }

        prevY = y;
        answer = (double)prevY;
    }
    free(events);
    free(xs);
    free(st.cover);
    free(st.len);
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
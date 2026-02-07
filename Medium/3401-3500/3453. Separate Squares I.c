// 3453. Separate Squares I
//
// You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents 
// the coordinates of the bottom-left point and the side length of a square parallel 
// to the x-axis.
// 
// Find the minimum y-coordinate value of a horizontal line such that the total area 
// of the squares above the line equals the total area of the squares below the line.
// 
// Answers within 10-5 of the actual answer will be accepted.
// 
// Note: Squares may overlap. Overlapping areas should be counted multiple times.
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
// Any horizontal line between y = 1 and y = 2 will have 1 square unit above 
// it and 1 square unit below it. The lowest option is 1.
// 
// Example 2:
// 
// Input: squares = [[0,0,2],[1,1,1]]
// 
// Output: 1.16667
// 
// Explanation:
// 
// y
// 4 |
// 3 |
// 2 | ####### 
//   | ####### 
// 1 |----------- - - - - - -   y ≈ 1.1667
//   | #######
// 0 | #######
//   +------------------------
//     0   1   2   3   4      x
// 
// The areas are:
// 
// Below the line: 7/6 * 2 (Red) + 1/6 (Blue) = 15/6 = 2.5.
// Above the line: 5/6 * 2 (Red) + 5/6 (Blue) = 15/6 = 2.5.
// Since the areas above and below the line are equal, the output is 7/6 = 1.16667.
// 
// 
// Constraints:
// 
// 1 <= squares.length <= 5 * 10^4
// squares[i] = [xi, yi, li]
// squares[i].length == 3
// 0 <= xi, yi <= 10^9
// 1 <= li <= 10^9
// The total area of all the squares will not exceed 10^12.

#include <stdlib.h>     // malloc, free, qsort
#include <stddef.h>     // size_t

struct Event{
    long long y;
    long long deltaSlope;   // +l at start, -l at end
};

static int compareEventByY(const void *a, const void *b){
    const struct Event *ea;
    const struct Event *eb;
    ea = (const struct Event *)a;
    eb = (const struct Event *)b;
    if (ea->y < eb->y) return -1;
    if (ea->y > eb->y) return 1;
    return 0;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize){
    struct Event *events;
    int m;
    int i;
    long double totalArea;
    long double target;
    long double currentArea;
    long double currentSlope;
    long long currentY;
    int idx;
    (void)squaresColSize;
    if (squares == NULL || squaresSize <= 0) return 0.0;
    events = (struct Event *)malloc((size_t)(2 * squaresSize) * sizeof(struct Event));
    if (events == NULL) return 0.0;
    totalArea = 0.0L;
    m = 0;
    for (i = 0; i < squaresSize; i++) {
        long long y0;
        long long l;

        y0 = (long long)squares[i][1];
        l  = (long long)squares[i][2];

        totalArea += (long double)l * (long double)l;

        events[m].y = y0;
        events[m].deltaSlope = +l;
        m++;

        events[m].y = y0 + l;
        events[m].deltaSlope = -l;
        m++;
    }
    qsort(events, (size_t)m, sizeof(struct Event), compareEventByY);
    target = totalArea / 2.0L;
    currentArea = 0.0L;
    currentSlope = 0.0L;
    currentY = events[0].y;
    idx = 0;
    while (idx < m) {
        long long y;
        long long dy;
        long double segArea;
        y = events[idx].y;
        if (y > currentY) {
            dy = y - currentY;
            segArea = currentSlope * (long double)dy;
            if (currentSlope > 0.0L && target <= currentArea + segArea) {
                long double need;
                long double answerY;
                need = target - currentArea;
                answerY = (long double)currentY + need / currentSlope;
                free(events);
                return (double)answerY;
            }
            currentArea += segArea;
            currentY = y;
        }
        // if exactly at breakpoint
        if (currentArea == target) {
            free(events);
            return (double)currentY;
        }
        while (idx < m && events[idx].y == y) {
            currentSlope += (long double)events[idx].deltaSlope;
            idx++;
        }
    }
    // Fallback: should end at top
    free(events);
    return (double)currentY;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
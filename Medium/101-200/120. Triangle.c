// 120. Triangle
// 
// Given a triangle array, return the minimum path sum from top to bottom.
// 
// For each step, you may move to an adjacent number of the row below. 
// More formally, if you are on index i on the current row, you may move to 
// either index i or index i + 1 on the next row.
// 
// 
// Example 1:
// 
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// 
// Example 2:
// 
// Input: triangle = [[-10]]
// Output: -10
// 
// Constraints:
// 
// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -10^4 <= triangle[i][j] <= 10^4
//  
// 
// Follow up: Could you do this using only O(n) extra space, where n is 
// the total number of rows in the triangle?

#include <stdlib.h>     // malloc, free
#include <stddef.h>     // size_t

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int *dp;
    int row, col;
    int lastRowCols;
    int left, right;
    int best;
    if (triangle == NULL || triangleSize <= 0 || triangleColSize == NULL){
        return 0;
    }
    dp = (int *)malloc((size_t)triangleSize * sizeof(int));
    if (dp == NULL) return 0;
    lastRowCols = triangleColSize[triangleSize - 1];
    for (col = 0; col < lastRowCols; col++){
        dp[col] = triangle[triangleSize - 1][col];
    }
    for (row = triangleSize - 2; row >= 0; row--){
        for (col = 0; col < triangleColSize[row]; col++){
            left = dp[col];
            right = dp[col + 1];
            best = (left < right) ? left : right;
            dp[col] = triangle[row][col] + best;
        }
    }
    best = dp[0];
    free(dp);
    return best;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
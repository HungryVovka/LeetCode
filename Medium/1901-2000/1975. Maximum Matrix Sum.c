// 1975. Maximum Matrix Sum
//
// You are given an n x n integer matrix. You can do the following operation 
// any number of times:
// 
// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.
// 
// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of // the matrix's elements using the operation mentioned above.
// 
// Example 1:
// 
// +----+----+      +----+----+
// |  1 | -1 |  →   |  1 |  1 |
// +----+----+      +----+----+
// | -1 |  1 |      |  1 |  1 |
// +----+----+      +----+----+
// 
// Input: matrix = [[1,-1],[-1,1]]
// Output: 4
// Explanation: We can follow the following steps to reach sum equals 4:
// - Multiply the 2 elements in the first row by -1.
// - Multiply the 2 elements in the first column by -1.
// 
// Example 2:
// 
// +----+----+----+      +----+----+----+
// |  1 |  2 |  3 |  →   |  1 |  2 |  3 |
// +----+----+----+      +----+----+----+
// | -1 | -2 | -3 |      |  1 |  2 |  3 |
// +----+----+----+      +----+----+----+
// |  1 |  2 |  3 |      |  1 |  2 |  3 |
// +----+----+----+      +----+----+----+
// 
// Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
// Output: 16
// Explanation: We can follow the following step to reach sum equals 16:
// - Multiply the 2 last elements in the second row by -1.
//  
// 
// Constraints:
// 
// n == matrix.length == matrix[i].length
// 2 <= n <= 250
// -10^5 <= matrix[i][j] <= 10^5

#include <stddef.h>         // size_t
#include <limits.h>         // INT_MAX
#include <stdlib.h>         // abs

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    long long sumAbs;
    int negativeCount;
    int minAbs;

    sumAbs = 0;
    negativeCount = 0;
    minAbs = INT_MAX;

    for (i = 0; i < matrixSize; i++){
        for (j = 0; j < matrixColSize[i]; j++){
            int value;
            int absValue;
            value = matrix[i][j];
            absValue = abs(value);
            sumAbs += absValue;
            if (value < 0) negativeCount++;
            if (absValue < minAbs) minAbs = absValue;
        }
    }
    if ((negativeCount % 2) == 0) return sumAbs;
    return sumAbs - 2LL * minAbs;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
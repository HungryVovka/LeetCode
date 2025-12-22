// 960. Delete Columns to Make Sorted III
// 
// You are given an array of n strings strs, all of the same length.
// 
// We may choose any deletion indices, and we delete all the characters in those indices 
// for each string.
// 
// For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then 
// the final array after deletions is ["bef", "vyz"].
// 
// Suppose we chose a set of deletion indices answer such that after deletions, the final 
// array has every string (row) in lexicographic order. 
// (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), 
// and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). 
// Return the minimum possible value of answer.length.
// 
// 
// Example 1:
// 
// Input: strs = ["babca","bbazb"]
// Output: 3
// Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["bc", "az"].
// Both these rows are individually in lexicographic order (ie. strs[0][0] <= strs[0][1] 
// and strs[1][0] <= strs[1][1]).
// Note that strs[0] > strs[1] - the array strs is not necessarily in lexicographic order.
// 
// Example 2:
// 
// Input: strs = ["edcba"]
// Output: 4
// Explanation: If we delete less than 4 columns, the only row will not be lexicographically 
// sorted.
// 
// Example 3:
// 
// Input: strs = ["ghi","def","abc"]
// Output: 0
// Explanation: All rows are already lexicographically sorted.
// 
// 
// Constraints:
// 
// n == strs.length
// 1 <= n <= 100
// 1 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

#include <stdlib.h>     // malloc, free
#include <string.h>     // strlen

static int columns_ok(char **strs, int row_count, int left_col, int right_col){
    int row;
    for (row = 0; row < row_count; row++){
        if (strs[row][left_col] > strs[row][right_col]) return 0;
    }
    return 1;
}

int lis_columns(char** strs, int row_count, int col_count){
    int col, prev_col;
    int *dp;
    int best_keep;
    int current_best;
    dp = (int *)malloc((size_t)col_count * sizeof(int));
    if (dp == NULL) return 0;
    for (col = 0; col < col_count; col++) dp[col] = 1;
    best_keep = 1;
    for (col = 0; col < col_count; col++){
        current_best = 1;
        for (prev_col = 0; prev_col < col; prev_col++){
            if (columns_ok(strs, row_count, prev_col, col)){
                if (dp[prev_col] + 1 > current_best){
                    current_best = dp[prev_col] +1;
                }
            }
        }
        dp[col] = current_best;
        if (dp[col] > best_keep) best_keep = dp[col]; 
    }
    free(dp);
    return best_keep;
}

int minDeletionSize(char** strs, int strsSize){
    int row_count;
    int col_count;
    int keep;
    if (strs == NULL || strsSize <= 0 || strs[0] == NULL) return 0;
    row_count = strsSize;
    col_count = (int)strlen(strs[0]);
    keep = lis_columns(strs, row_count, col_count);
    return col_count - keep;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
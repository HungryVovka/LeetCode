// 955. Delete Columns to Make Sorted II
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
// array has its elements in lexicographic order 
// (i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). Return the minimum possible 
// value of answer.length.
// 
// 
// Example 1:
// 
// Input: strs = ["ca","bb","ac"]
// Output: 1
// Explanation: 
// After deleting the first column, strs = ["a", "b", "c"].
// Now strs is in lexicographic order (ie. strs[0] <= strs[1] <= strs[2]).
// We require at least 1 deletion since initially strs was not in lexicographic order, 
// so the answer is 1.
// 
// Example 2:
// 
// Input: strs = ["xc","yb","za"]
// Output: 0
// Explanation: 
// strs is already in lexicographic order, so we do not need to delete anything.
// Note that the rows of strs are not necessarily in lexicographic order:
// i.e., it is NOT necessarily true that (strs[0][0] <= strs[0][1] <= ...)
// 
// Example 3:
// 
// Input: strs = ["zyx","wvu","tsr"]
// Output: 3
// Explanation: We have to delete every column.
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
#include <stdbool.h>    // bool

int minDeletionSize(char** strs, int strsSize){
    int n, m, col;
    int i;
    bool *fixed;
    int deletions;
    bool must_delete;
    if (strs == NULL || strsSize <= 0 || strs[0] == NULL) return 0;
    n = strsSize;
    m = (int)strlen(strs[0]);
    if (n <= 1) return 0;
    fixed = (bool *)malloc((size_t)(n - 1) * sizeof(bool));
    if (fixed == NULL) return 0;
    for (i = 0; i < n - 1; i++) fixed[i] = false;
    deletions = 0;
    for (col = 0; col < m; col++){
        must_delete = false;
        for (i = 0; i < n - 1; i++){
            if (!fixed[i] && strs[i][col] > strs[i + 1][col]){
                must_delete = true;
                break;;
            }
        }
        if (must_delete){
            deletions++;
            continue;
        }
        for (i = 0; i < n- 1; i++){ 
            if (!fixed[i] && strs[i][col] < strs[i + 1][col]) fixed[i] = true;
        }
    }
    free(fixed);
    return deletions;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
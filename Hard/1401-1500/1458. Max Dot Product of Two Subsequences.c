// 1458. Max Dot Product of Two Subsequences
//
// Given two arrays nums1 and nums2.
// 
// Return the maximum dot product between non-empty subsequences of nums1 and nums2 
// with the same length.
// 
// A subsequence of a array is a new array which is formed from the original array 
// by deleting some (can be none) of the characters without disturbing the relative 
// positions of the remaining characters. (ie, [2,3,5] is a subsequence 
// of [1,2,3,4,5] while [1,5,3] is not).
// 
// 
// Example 1:
// 
// Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
// Output: 18
// Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
// Their dot product is (2*3 + (-2)*(-6)) = 18.
// 
// Example 2:
// 
// Input: nums1 = [3,-2], nums2 = [2,-6,7]
// Output: 21
// Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
// Their dot product is (3*7) = 21.
// 
// Example 3:
// 
// Input: nums1 = [-1,-1], nums2 = [1,1]
// Output: -1
// Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
// Their dot product is -1.
//  
// 
// Constraints:
// 
// 1 <= nums1.length, nums2.length <= 500
// -1000 <= nums1[i], nums2[i] <= 1000

#include <stdlib.h>     // malloc, free
#include <limits.h>     // INT_MIN

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *dp;
    int i, j;
    int answer;
    if (nums1 == NULL || nums2 == NULL || nums1Size <= 0 || nums2Size <= 0){
        return 0;
    }
    dp = (int *)malloc((size_t)(nums2Size + 1) * sizeof(int));
    if (dp == NULL) return 0;
    for (j = 0; j <= nums2Size; j++) dp[j] = INT_MIN;
    answer = INT_MIN;
    for (i = 1; i <= nums1Size; i++){
        int prevDiag;
        int newDiag;
        prevDiag = INT_MIN;
        for (j = 1; j <= nums2Size; j++){
            int a, b;
            int prod;
            int best;
            int takePair;
            a = nums1[i - 1];
            b = nums2[j - 1];
            prod = a * b;
            newDiag = dp[j];
            if (prevDiag > 0){
                takePair = prevDiag + prod;
            } else {
                takePair = prod;
            }
            best = dp[j];
            if (dp[j - 1] > best) best = dp[j - 1];
            if (takePair > best) best = takePair;
            dp[j] = best;
            if (best > answer) answer = best;
            prevDiag = newDiag;
        }
    }
    free(dp);
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
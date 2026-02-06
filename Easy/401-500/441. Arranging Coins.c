// 441. Arranging Coins
//
// You have n coins and you want to build a staircase with these coins. 
// The staircase consists of k rows where the ith row has exactly i coins. The last 
// row of the staircase may be incomplete.
// 
// Given the integer n, return the number of complete rows of the staircase you will build.
// 
// Example 1:
// 
// [$]
// [$][$]
// [$][$][ ]
// 
// Input: n = 5
// Output: 2
// Explanation: Because the 3rd row is incomplete, we return 2.
// 
// Example 2:
// 
// [$]
// [$][$]
// [$][$][$]
// [$][$][ ][ ]
// 
// Input: n = 8
// Output: 3
// Explanation: Because the 4th row is incomplete, we return 3.
// 
// 
// Constraints:
// 
// 1 <= n <= 2^31 - 1

#include <limits.h>     // INT_MAX

int arrangeCoins(int n){
    long long left;
    long long right;
    long long answer;
    if (n <= 0) return 0;
    left = 0;
    right = (long long)n; // k cannot exceed n
    answer = 0;
    while (left <= right){
        long long mid;
        long long needed;
        mid = left + (right - left) / 2;
        needed = mid * (mid + 1) / 2;
        if (needed <= (long long)n){
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return (int)answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
// 507. Perfect Number
//
// A perfect number is a positive integer that is equal to the sum of 
// its positive divisors, excluding the number itself. A divisor of an 
// integer x is an integer that can divide x evenly.
// 
// Given an integer n, return true if n is a perfect number, otherwise return false.
// 
// 
// Example 1:
// 
// Input: num = 28
// Output: true
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
// 1, 2, 4, 7, and 14 are all divisors of 28.
// 
// Example 2:
// 
// Input: num = 7
// Output: false
//  
// 
// Constraints:
// 
// 1 <= num <= 10^8

#include <stdbool.h>    // bool
#include <math.h>       // sqrt

bool checkPerfectNumber(int num){
    int divisorSum;
    int limit;
    int i;
    if (num <= 1) return false;
    divisorSum = 1;
    limit = (int)sqrt((double)num);
    for (i = 2; i <= limit; ++i){
        if (num % i == 0){
            int otherDivisor;
            otherDivisor = num / i;
            divisorSum += i;
            if (otherDivisor != i) divisorSum += otherDivisor;
        }
    }
    return divisorSum == num;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
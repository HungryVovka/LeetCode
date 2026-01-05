// 1390. Four Divisors
//
// Given an integer array nums, return the sum of divisors of the integers in 
// that array that have exactly four divisors. If there is no such integer in 
// the array, return 0.
// 
// 
// Example 1:
// 
// Input: nums = [21,4,7]
// Output: 32
// Explanation: 
// 21 has 4 divisors: 1, 3, 7, 21
// 4 has 3 divisors: 1, 2, 4
// 7 has 2 divisors: 1, 7
// The answer is the sum of divisors of 21 only.
// 
// Example 2:
// 
// Input: nums = [21,21]
// Output: 64
// Example 3:
// 
// Input: nums = [1,2,3,4,5]
// Output: 0
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 10^4
// 1 <= nums[i] <= 10^5

#include <stdbool.h>        // bool
#include <stddef.h>         // size_t

static bool isPrimeInt(int x){
    int d;
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (d = 3; (long long)d * d <= (long long)x; d += 2){
        if (x % d == 0) return false;
    }
    return true;
}

static int intCubeRootFloor(int x){
    int lo, hi, mid;
    lo = 0;
    hi = 1000;
    while (lo < hi){
        mid = lo + (hi - lo + 1) / 2;
        if ((long long)mid * mid * mid <= (long long)x) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

static int sumIfFourDivisors(int x){
    int d, e, root;
    root = intCubeRootFloor(x);
    if (root >= 2){
        long long cube = (long long)root * root * root;
        if (cube == (long long)x && isPrimeInt(root)){
            long long p = root;
            long long sum = 1 + p + p * p + p * p * p;
            return (int)sum;
        }
    }
    for (d = 2; (long long)d * d <= (long long)x; d++){
        if (x % d == 0){
            e = x / d;
            if (e == d) return 0;
            if (isPrimeInt(d) && isPrimeInt(e)){
                return 1 + d + e + x;
            }
            return 0;
        }
    }
    return 0;
}

int sumFourDivisors(int* nums, int numsSize){
    int i;
    long long total;
    if (nums == NULL || numsSize <= 0) return 0;
    total = 0;
    for (i = 0; i < numsSize; i++){
        total += (long long)sumIfFourDivisors(nums[i]);
    }
    return (int)total;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
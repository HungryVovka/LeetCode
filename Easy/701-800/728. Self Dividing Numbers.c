// 728. Self Dividing Numbers
//
// A self-dividing number is a number that is divisible by every digit it contains.
// 
// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, 
// and 128 % 8 == 0.
// 
// A self-dividing number is not allowed to contain the digit zero.
// 
// Given two integers left and right, return a list of all the self-dividing numbers 
// in the range [left, right] (both inclusive).
// 
// 
// Example 1:
// 
// Input: left = 1, right = 22
// Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
// 
// Example 2:
// 
// Input: left = 47, right = 85
// Output: [48,55,66,77]
//  
// 
// Constraints:
// 
// 1 <= left <= right <= 10^4

#include <stdlib.h>     // malloc

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int isSelfDividing(int value){
    int original;
    int digit;
    original = value;
    while (value > 0){
        digit = value % 10;
        if (digit == 0) return 0;
        if (original % digit != 0) return 0;
        value /= 10;
    }
    return 1;
}

int* selfDividingNumbers(int left, int right, int* returnSize){
    int capacity;
    int count;
    int current;
    int *result;
    capacity = right - left + 1;
    result = (int *)malloc(capacity * sizeof(int));
    count = 0;
    for (current = left; current <= right; ++current){
        if (isSelfDividing(current)){
            result[count] = current;
            count++;
        }
    }
    *returnSize = count;
    return result;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
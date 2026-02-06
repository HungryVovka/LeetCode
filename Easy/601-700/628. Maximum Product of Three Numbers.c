// 628. Maximum Product of Three Numbers
//
// Given an integer array nums, find three numbers whose product 
// is maximum and return the maximum product.
// 
// 
// Example 1:
// 
// Input: nums = [1,2,3]
// Output: 6
// 
// Example 2:
// 
// Input: nums = [1,2,3,4]
// Output: 24
// 
// Example 3:
// 
// Input: nums = [-1,-2,-3]
// Output: -6
//  
// 
// Constraints:
// 
// 3 <= nums.length <= 10^4
// -1000 <= nums[i] <= 1000

#include <limits.h>     // INT_MIN, INT_MAX

int maximumProduct(int* nums, int numsSize){
    int max1, max2, max3;
    int min1, min2;
    int i;
    max1 = INT_MIN;
    max2 = INT_MIN;
    max3 = INT_MIN;
    min1 = INT_MAX;
    min2 = INT_MAX;
    for (i = 0; i < numsSize; ++i){
        int value;
        value = nums[i];
        if (value > max1){
            max3 = max2;
            max2 = max1;
            max1 = value;
        } else if (value > max2){
            max3 = max2;
            max2 = value;
        } else if (value > max3){
            max3 = value;
        }
        if (value < min1){
            min2 = min1;
            min1 = value;
        } else if (value < min2){
            min2 = value;
        }
    }
    int productA, productB;
    productA = max1 * max2 * max3;
    productB = max1 * min1 * min2;
    return (productA > productB) ? productA : productB;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
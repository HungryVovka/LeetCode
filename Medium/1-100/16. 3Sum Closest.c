// 16. 3Sum Closest
//
// Given an integer array nums of length n and an integer target, 
// find three integers at distinct indices in nums such that 
// the sum is closest to target.
// 
// Return the sum of the three integers.
// 
// You may assume that each input would have exactly one solution.
//  
// 
// Example 1:
// 
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// 
// Example 2:
// 
// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
//  
// 
// Constraints:
// 
// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -10^4 <= target <= 10^4

#include <stdlib.h>     // qsort, abs

int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}


int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), cmp);
    int closest = nums[0] + nums[1] + nums[2];
    int i;
    int l, r;
    int sum;
    for (i = 0; i < numsSize - 2; i++){
        l = i + 1;
        r = numsSize - 1;
        while(l < r){
            sum = nums[i] + nums[l] + nums[r];
            if (abs(target - sum) < abs(target - closest)){
                closest = sum;
            }
            if (sum < target){
                l++;
            } else if (sum > target){
                r--;
            } else {
                return target;
            }
        }
    }
    return closest;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
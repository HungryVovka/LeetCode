// 3507. Minimum Pair Removal to Sort Array I
//
// Given an array nums, you can perform the following operation any number of times:
// 
// Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, 
// choose the leftmost one.
// Replace the pair with their sum.
// 
// Return the minimum number of operations needed to make the array non-decreasing.
// 
// An array is said to be non-decreasing if each element is greater than or equal to 
// its previous element (if it exists).
//  
// 
// Example 1:
// 
// Input: nums = [5,2,3,1]
// 
// Output: 2
// 
// Explanation:
// 
// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
// The array nums became non-decreasing in two operations.
// 
// Example 2:
// 
// Input: nums = [1,2,2]
// 
// Output: 0
// 
// Explanation:
// 
// The array nums is already sorted.
// 
// 
// Constraints:
// 
// 1 <= nums.length <= 50
// -1000 <= nums[i] <= 1000

#include <limits.h>     // INT_MAX

int isNonDecreasing(const int* nums, int numsSize){
    int i;
    for (i = 1; i < numsSize; ++i){
        if (nums[i] < nums[i - 1]) return 0;
    }
    return 1;
}

int minimumPairRemoval(int *nums, int numsSize){
    int operations;
    int i;
    operations = 0;
    while (numsSize > 1 && !isNonDecreasing(nums, numsSize)){
        int bestIndex;
        int bestSum;
        bestIndex = 0;
        bestSum = nums[0] + nums[1];
        // Find leftmost adjacent pair with minimum sum
        for (i = 1; i < numsSize - 1; ++i){
            int currentSum;
            currentSum = nums[i] + nums[i + 1];
            if (currentSum < bestSum){
                bestSum = currentSum;
                bestIndex = i;
            }
        }
        // Replace nums[bestIndex] and nums[bestIndex+1] with their sum
        nums[bestIndex] = bestSum;
        // Shift left to remove nums[bestIndex+1]
        for (i = bestIndex + 1; i < numsSize - 1; ++i){
            nums[i] = nums[i + 1];
        }
        numsSize--;
        operations++;
    }
    return operations;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
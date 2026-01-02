// 961. N-Repeated Element in Size 2N Array
//
// You are given an integer array nums with the following properties:
// 
// nums.length == 2 * n.
// nums contains n + 1 unique elements.
// Exactly one element of nums is repeated n times.
// Return the element that is repeated n times.
// 
// 
// Example 1:
// 
// Input: nums = [1,2,3,3]
// Output: 3
// 
// Example 2:
// 
// Input: nums = [2,1,2,5,3,2]
// Output: 2
// 
// Example 3:
// 
// Input: nums = [5,1,5,2,5,3,5,4]
// Output: 5
//  
// 
// Constraints:
// 
// 2 <= n <= 5000
// nums.length == 2 * n
// 0 <= nums[i] <= 10^4
// nums contains n + 1 unique elements and one of them is repeated exactly n times.

int repeatedNTimes(int* nums, int numsSize){
    int limit;
    int i, j;
    if (nums == NULL || numsSize <= 0) return -1;
    limit = (numsSize < 4) ? numsSize : 4;
    for (i = 0; i < limit; i++){
        for (j = i + 1; j < limit; j++){
            if (nums[i] == nums[j]) return nums[i];
        }
    }
    for (i = 1; i < numsSize; i++){
        if (i + 1 < numsSize && nums[i] == nums[i + 1]) return nums[i];
        if (i + 2 < numsSize && nums[i] == nums[i + 2]) return nums[i];
        if (i + 3 < numsSize && nums[i] == nums[i + 3]) return nums[i];
    }
    return -1;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
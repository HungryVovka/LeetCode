// 283. Move Zeroes
// 
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// 
// Note that you must do this in-place without making a copy of the array.
// 
// Example 1:
// 
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// 
// Example 2:
// 
// Input: nums = [0]
// Output: [0]
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 10^4
// -2^31 <= nums[i] <= 2^31 - 1
// 
// Follow up: Could you minimize the total number of operations done?

public class Solution
{
    public void MoveZeroes(int[] nums)
    {
        int index = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] != 0)
            {
                nums[index] = nums[i];
                index++;
            }
        }
        while (index < nums.Length)
        {
            nums[index] = 0;
            index++;
        }
    }
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
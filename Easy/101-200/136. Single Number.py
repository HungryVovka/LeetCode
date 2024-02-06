# 136. Single Number
# 
# Given a non-empty array of integers nums, every element appears twice except for one. Find 
# that single one.
# 
# You must implement a solution with a linear runtime complexity and use only constant extra 
# space.
# 
# Example 1:
# Input: nums = [2,2,1]
# Output: 1
# 
# Example 2:
# Input: nums = [4,1,2,1,2]
# Output: 4
# 
# Example 3:
# Input: nums = [1]
# Output: 1
# 
# Constraints:
# 
# 1 <= nums.length <= 3 * 10^4
# -3 * 10^4 <= nums[i] <= 3 * 10^4
# Each element in the array appears twice except for one element which appears only 
# once.

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        digit_count = {}
        for i in nums:
            if i in digit_count:
                digit_count[i] += 1
            else:
                digit_count[i] = 1
        for key, value in digit_count.items():
            if value == 1:
                return key

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
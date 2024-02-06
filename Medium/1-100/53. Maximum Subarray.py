# 53. Maximum Subarray
# 
# Given an integer array nums, find the subarray with the largest sum, and return its sum.
# 
# Example 1:
# Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
# Output: 6
# Explanation: The subarray [4,-1,2,1] has the largest sum 6.
# 
# Example 2:
# Input: nums = [1]
# Output: 1
# Explanation: The subarray [1] has the largest sum 1.
# 
# Example 3:
# Input: nums = [5,4,-1,7,8]
# Output: 23
# Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
#  
# Constraints:
# 
# 1 <= nums.length <= 10^5
# -10^4 <= nums[i] <= 10^4

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sub, curr_sub = nums[0], nums[0]
        for i in range(1, len(nums)):
            curr_sub = max(nums[i], curr_sub + nums[i])
            max_sub = max(max_sub, curr_sub)
        return max_sub

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
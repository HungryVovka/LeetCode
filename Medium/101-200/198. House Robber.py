# 198. House Robber
# 
# You are a professional robber planning to rob houses along a street. Each house has a certain amount of 
# money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have 
# security systems connected and it will automatically contact the police if two adjacent houses were 
# broken into on the same night.
# 
# Given an integer array nums representing the amount of money of each house, return the maximum 
# amount of money you can rob tonight without alerting the police.
# 
# Example 1:
# Input: nums = [1,2,3,1]
# Output: 4
# Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
# Total amount you can rob = 1 + 3 = 4.
# 
# Example 2:
# Input: nums = [2,7,9,3,1]
# Output: 12
# Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 
# 5 (money = 1).
# Total amount you can rob = 2 + 9 + 1 = 12.
# 
# Constraints:
# 
# 1 <= nums.length <= 100
# 0 <= nums[i] <= 400

class Solution:
    def rob(self, nums: List[int]) -> int:
        max_x0, max_x1 = 0, 0
        update_max = lambda a: max(max_x0 + a, max_x1)
        for i in nums:
            max_x2 = update_max(i)
            max_x0 = max_x1
            max_x1 = max_x2
        return max_x1

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
# 18. 4Sum
# 
# Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], 
# nums[b], nums[c], nums[d]] such that:
# 
# 0 <= a, b, c, d < n
# a, b, c, and d are distinct.
# nums[a] + nums[b] + nums[c] + nums[d] == target
# 
# You may return the answer in any order.
# 
# Example 1:
# Input: nums = [1,0,-1,0,-2,2], target = 0
# Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
# 
# Example 2:
# Input: nums = [2,2,2,2,2], target = 8
# Output: [[2,2,2,2]]
# 
# Constraints:
# 
# 1 <= nums.length <= 200
# -10^9 <= nums[i] <= 10^9
# -10^9 <= target <= 10^9

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        answer = []
        n = len(nums)
        nums.sort()
        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i + 1, n - 2):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                left = j + 1
                right = n - 1
                self._find_two_sum(nums, target, i, j, left, right, answer)
        return answer
    
    def _find_two_sum(self, nums, target, i, j, left, right, answer):
        while left < right:
            total = nums[i] + nums[j] + nums[left] + nums[right]     
            if total == target:
                answer.append([nums[i], nums[j], nums[left], nums[right]])
                left, right = self._check_duplicates(nums, left, right)
            elif total < target:
                left += 1
            else:
                right -= 1
    
    def _check_duplicates(self, nums, left, right):
        while left < right and nums[left] == nums[left+1]:
            left += 1
        while left < right and nums[right] == nums[right-1]:
            right -= 1
        return left + 1, right - 1

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
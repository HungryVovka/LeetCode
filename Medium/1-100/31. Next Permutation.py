# 31. Next Permutation
# 
# A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
# 
# For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], 
# [2, 3, 1], [3,1,2], [3,2,1].
# 
# The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More 
# formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the 
# next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not 
# possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
# 
# For example, the next permutation of arr = [1,2,3] is [1,3,2].
# Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
# While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical 
# larger rearrangement.
# 
# Given an array of integers nums, find the next permutation of nums.
# 
# The replacement must be in place and use only constant extra memory.
# 
# Example 1:
# 
# Input: nums = [1,2,3]
# Output: [1,3,2]
# 
# Example 2:
# 
# Input: nums = [3,2,1]
# Output: [1,2,3]
# 
# Example 3:
# 
# Input: nums = [1,1,5]
# Output: [1,5,1]
# 
# Constraints:
# 
# 1 <= nums.length <= 100
# 0 <= nums[i] <= 100

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        a = self.first_decreasing(nums)
        if a == -1:
            self.reverse_array(nums)
            return
        b = self.smallest_greater(nums, a)
        self.swap_elements(nums, a, b)
        self.reverse_subarray(nums, a + 1)

    def first_decreasing(self, nums):
        a = len(nums) - 2
        while a >= 0 and nums[a] >= nums[a+1]:
            a -= 1
        return a

    def reverse_array(self, nums):
        nums.reverse()

    def smallest_greater(self, nums, a):
        b = len(nums) - 1
        while b > 1 and nums[b] <= nums[a]:
            b -= 1
        return b

    def swap_elements(self, nums, a, b):
        nums[a], nums[b] = nums[b], nums[a]

    def reverse_subarray(self, nums, start):
        end = len(nums) - 1
        while start < end:
            self.swap_elements(nums, start, end)
            start += 1
            end -= 1

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
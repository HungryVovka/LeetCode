# 169. Majority Element
# 
# Given an array nums of size n, return the majority element.
# 
# The majority element is the element that appears more than ⌊n / 2⌋ times. You may 
# assume that the majority element always exists in the array.
# 
# Example 1:
# Input: nums = [3,2,3]
# Output: 3
# 
# Example 2:
# Input: nums = [2,2,1,1,1,2,2]
# Output: 2
# 
# Constraints:
# 
# n == nums.length
# 1 <= n <= 5 * 10^4
# -10^9 <= nums[i] <= 10^9

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        element_count = {}
        for i in nums:
            if i in element_count:
                element_count[i] += 1
            else:
                element_count[i] = 1
        return max(element_count, key=element_count.get)

# or

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        element_count = 0
        majority = None
        for i in nums:
            if element_count == 0:
                majority = i
            if i == majority:
                element_count += 1
            else:
                element_count -= 1
        return majority

# or

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        element_count = 0
        majority = 0
        for i in nums:
            if element_count == 0:
                majority = i
                element_count += 1
            elif i == majority:
                element_count += 1
            else:
                element_count -= 1
        return majority

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
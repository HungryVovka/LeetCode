# 645. Set Mismatch
# 
# You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to 
# some error, one of the numbers in s got duplicated to another number in the set, which results in 
# repetition of one number and loss of another number.
# 
# You are given an integer array nums representing the data status of this set after the error.
# 
# Find the number that occurs twice and the number that is missing and return them in the form of an array.
# 
# Example 1:
# Input: nums = [1,2,2,4]
# Output: [2,3]
# 
# Example 2:
# Input: nums = [1,1]
# Output: [1,2]
# 
# Constraints:
# 
# 2 <= nums.length <= 104
# 1 <= nums[i] <= 104

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        unique = {}
        duplicate, missing = -1, -1
        for i in nums:
            if i in unique:
                duplicate = i
            else:
                unique[i] = 1
        for j in range(1, len(nums) + 1):
            if j not in unique:
                missing = j
                break
        return [duplicate, missing]

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
# 446. Arithmetic Slices II - Subsequence
# 
# Given an integer array nums, return the number of all the arithmetic subsequences of nums.
# 
# A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any 
# two consecutive elements is the same.
# 
# For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
# For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
# 
# A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
# 
# For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
# The test cases are generated so that the answer fits in 32-bit integer.
# 
# Example 1:
# 
# Input: nums = [2,4,6,8,10]
# Output: 7
# Explanation: All arithmetic subsequence slices are:
# [2,4,6]
# [4,6,8]
# [6,8,10]
# [2,4,6,8]
# [4,6,8,10]
# [2,4,6,8,10]
# [2,6,10]
# 
# Example 2:
# 
# Input: nums = [7,7,7,7,7]
# Output: 16
# Explanation: Any subsequence of this array is arithmetic.
# 
# Constraints:
# 
# 1  <= nums.length <= 1000
# -2^31 <= nums[i] <= 2^31 - 1

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        answer = 0
        n = len(nums)
        subsequences = [{} for i in range(n)]
        for x in range(n):
            for y in range(x):
                difference = nums[x] - nums[y]
                subsequences[x][difference] = \
                subsequences[x].get(difference, 0) + \
                subsequences[y].get(difference, 0) + 1
                answer += subsequences[y].get(difference, 0)
        return answer


# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
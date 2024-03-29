# 47. Permutations II
# 
# Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
# 
# Example 1:
# 
# Input: nums = [1,1,2]
# Output:
# [[1,1,2],
#  [1,2,1],
#  [2,1,1]]
# 
# Example 2:
# 
# Input: nums = [1,2,3]
# Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
# 
# Constraints:
# 
# 1 <= nums.length <= 8
# -10 <= nums[i] <= 10

from itertools import permutations

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        return list(set(permutations(nums)))

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
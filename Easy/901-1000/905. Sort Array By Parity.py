# 905. Sort Array By Parity
# 
# Given an integer array nums, move all the even integers at the beginning of the array 
# followed by all the odd integers.
# 
# Return any array that satisfies this condition.
# 
# Example 1:
# Input: nums = [3,1,2,4]
# Output: [2,4,3,1]
# Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] 
# would also be accepted.
# 
# Example 2:
# Input: nums = [0]
# Output: [0]
# 
# Constraints:
# 
# 1 <= nums.length <= 5000
# 0 <= nums[i] <= 5000

class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        even = list(filter(lambda x: x % 2 == 0, nums))
        odd = list(filter(lambda x: x % 2 != 0, nums))
        return even + odd

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
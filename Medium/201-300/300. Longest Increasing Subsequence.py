# 300. Longest Increasing Subsequence
# 
# Given an integer array nums, return the length of the longest strictly increasing subsequence.
# 
# Example 1:
# 
# Input: nums = [10,9,2,5,3,7,101,18]
# Output: 4
# Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
# 
# Example 2:
# 
# Input: nums = [0,1,0,3,2,3]
# Output: 4
# 
# Example 3:
# 
# Input: nums = [7,7,7,7,7,7,7]
# Output: 1
# 
# Constraints:
# 
# 1 <= nums.length <= 2500
# -10^4 <= nums[i] <= 10^4

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        longest = [nums[0]]
        for i in nums[1:]:
            if i < longest[0]:
                longest[0] = i
            elif i > longest[-1]:
                longest.append(i)
            else:
                left, right = 0, len(longest) - 1
                while left < right:
                    middle = (left + right) // 2
                    if longest[middle] < i:
                        left = middle + 1
                    else:
                        right = middle
                longest[right] = i
        return len(longest)

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
# 1493. Longest Subarray of 1's After Deleting One Element
# Given a binary array nums, you should delete one element from it.
# 
# Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
# 
# Example 1:
# 
# Input: nums = [1,1,0,1]
# Output: 3
# Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
# 
# Example 2:
# 
# Input: nums = [0,1,1,1,0,1,1,0,1]
# Output: 5
# Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
# 
# Example 3:
# 
# Input: nums = [1,1,1]
# Output: 2
# Explanation: You must delete one element.
# 
# Constraints:
# 
# 1 <= nums.length <= 10^5
# nums[i] is either 0 or 1.

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        arr = [0] * len(nums)
        arr[0] = nums[0]
        longest, count = 0, 0
        print(arr, nums)
        for i in range(1, len(nums)):
            print(arr, nums)
            if nums[i] == 1:
                arr[i] = arr[i-1] + 1
            else:
                if nums[i-1] != 0:
                    arr[i] = arr[i-1] - count
                    count = arr[i]
                else:
                    count = 0
            longest = max(longest, arr[i])
        print(arr, nums)
        return longest - 1 if longest == len(nums) else longest

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
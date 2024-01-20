# 907. Sum of Subarray Minimums
# 
# Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray 
# of arr. Since the answer may be large, return the answer modulo 109 + 7.
# 
# Example 1:
# Input: arr = [3,1,2,4]
# Output: 17
# Explanation: 
# Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
# Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
# Sum is 17.
# 
# Example 2:
# Input: arr = [11,81,94,43,3]
# Output: 444
# 
# Constraints:
# 
# 1 <= arr.length <= 3 * 104
# 1 <= arr[i] <= 3 * 104

class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        answer = 0
        mod = int(1e9 + 7)
        stack = []
        count = [0] * len(arr)
        for i, num in enumerate(arr):
            while stack and num <= arr[stack[-1]]:
                stack.pop()
            prev = stack[-1] if stack else -1
            if prev != -1:
                count[i] = (i - prev) * num + count[prev]
            else:
                count[i] = (i - prev) * num
            answer += count[i]
            stack.append(i)
        return answer % mod

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
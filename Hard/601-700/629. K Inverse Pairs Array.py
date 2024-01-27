# 629. K Inverse Pairs Array
# 
# For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < 
# nums.length and nums[i] > nums[j].
# 
# Given two integers n and k, return the number of different arrays consist of numbers from 1 
# to n such that there are exactly k inverse pairs. Since the answer can be huge, return it 
# modulo 109 + 7.
# 
# Example 1:
# Input: n = 3, k = 0
# Output: 1
# Explanation: Only the array [1,2,3] which consists of numbers 
# from 1 to 3 has exactly 0 inverse pairs.
# 
# Example 2:
# Input: n = 3, k = 1
# Output: 2
# Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse 
# pair.
# 
# Constraints:
# 
# 1 <= n <= 1000
# 0 <= k <= 1000

class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        mod = int(1e9 + 7)
        dp = [[0] * (k + 1) for i in range(2)]
        dp[0][0] = 1
        for x in range(1, n + 1):
            dp[x%2] = [0] * (k + 1)
            dp[x%2][0] = 1
            for x0 in range(1, k + 1):
                dp[x%2][x0] = (dp[x%2][x0-1] + dp[(x - 1)%2][x0]) % mod
                if x0 - x >= 0:
                    dp[x%2][x0] = (dp[x%2][x0] - dp[(x - 1)%2][x0-x]) % mod
        return dp[n%2][k]

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
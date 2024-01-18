# 70. Climbing Stairs
# 
# You are climbing a staircase. It takes n steps to reach the top.
# 
# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
# 
# Example 1:
# Input: n = 2
# Output: 2
# Explanation: There are two ways to climb to the top.
# 1. 1 step + 1 step
# 2. 2 steps
# 
# Example 2:
# Input: n = 3
# Output: 3
# Explanation: There are three ways to climb to the top.
# 1. 1 step + 1 step + 1 step
# 2. 1 step + 2 steps
# 3. 2 steps + 1 step
# 
# Constraints:
# 
# 1 <= n <= 45

class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1 or n == 2:
            return n
        ways = [0] * (n + 1)
        ways[1], ways[2] = 1, 2
        for i in range(3, n + 1):
            ways[i] = ways[i-1] + ways[i-2]
        return ways[n]

# or

class Solution:
    def climbStairs(self, n: int) -> int:
        ways = {0: 1, 1: 1, 2: 2}
        i = 3
        while i <= n:
            ways[i] = ways[i-1] + ways[i-2]
            i += 1
        return ways[n]

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
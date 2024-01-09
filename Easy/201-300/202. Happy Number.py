# 202. Happy Number
# 
# Write an algorithm to determine if a number n is happy.
# 
# A happy number is a number defined by the following process:
# 
# Starting with any positive integer, replace the number by the sum of the squares of its digits.
# Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not 
# include 1.
# Those numbers for which this process ends in 1 are happy.
# 
# Return true if n is a happy number, and false if not.
# 
# Example 1:
# 
# Input: n = 19
# Output: true
# Explanation:
# 1^2 + 9^2 = 82
# 8^2 + 2^2 = 68
# 6^2 + 8^2 = 100
# 1^2 + 0^2 + 0^2 = 1
# 
# Example 2:
# 
# Input: n = 2
# Output: false
# 
# Constraints:
# 
# 1 <= n <= 2^31 - 1

class Solution:
    def isHappy(self, n: int) -> bool:
        def pow_repeat(x):
            sq_sum = 0
            while x > 0:
                digit = x % 10
                sq_sum += digit**2
                x //= 10
            return sq_sum

        happy_variations = set()
        while n != 1 and n not in happy_variations:
            happy_variations.add(n)
            n = pow_repeat(n)
        return n == 1

# or

class Solution:
    def isHappy(self, n: int) -> bool:
        def pow_repeat(x):
            sq_sum = 0
            while x > 0:
                x, digit = divmod(x, 10)
                sq_sum += digit**2
            return sq_sum

        happy_variations = set()
        while n != 1 and n not in happy_variations:
            happy_variations.add(n)
            n = pow_repeat(n)
        return n == 1

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
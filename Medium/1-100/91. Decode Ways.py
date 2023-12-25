# 91. Decode Ways
# 
# A message containing letters from A-Z can be encoded into numbers using the following mapping:
# 
# 'A' -> "1"
# 'B' -> "2"
# ...
# 'Z' -> "26"
# 
# To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the 
# mapping above (there may be multiple ways). For example, "11106" can be mapped into:
# 
# "AAJF" with the grouping (1 1 10 6)
# "KJF" with the grouping (11 10 6)
# 
# Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from 
# "06".
# 
# Given a string s containing only digits, return the number of ways to decode it.
# 
# The test cases are generated so that the answer fits in a 32-bit integer.
# 
# Example 1:
# 
# Input: s = "12"
# Output: 2
# Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
# 
# Example 2:
# 
# Input: s = "226"
# Output: 3
# Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
# 
# Example 3:
# 
# Input: s = "06"
# Output: 0
# Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
# 
# Constraints:
# 
# 1 <= s.length <= 100
# s contains only digits and may contain leading zero(s).

class Solution:
    def numDecodings(self, s: str) -> int:
        if len(s) == 0:
            return 0
        arr = [0] * (len(s) + 1)
        arr[0] = 1
        if s[0] != "0":
            arr[1] = 1
        i = 2
        single_digit_valid = lambda x: s[x - 1: x] != "0"
        while i <= len(s):
            if single_digit_valid(i):
                arr[i] += arr[i - 1]
            double_digit_valid = lambda x: "10" <= s[x - 2: x] <= "26"
            if double_digit_valid(i):
                arr[i] += arr[i - 2]
            i += 1
        return arr[len(s)]

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
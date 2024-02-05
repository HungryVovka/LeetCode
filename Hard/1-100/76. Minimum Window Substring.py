# 76. Minimum Window Substring
# 
# Given two strings s and t of lengths m and n respectively, return the minimum window 
# substring of s such that every character in t (including duplicates) is included in the 
# window. If there is no such substring, return the empty string "".
# 
# The testcases will be generated such that the answer is unique.
# 
# Example 1:
# Input: s = "ADOBECODEBANC", t = "ABC"
# Output: "BANC"
# Explanation: The minimum window substring "BANC" includes 'A', 
# 'B', and 'C' from string t.
# 
# Example 2:
# Input: s = "a", t = "a"
# Output: "a"
# Explanation: The entire string s is the minimum window.
# 
# Example 3:
# Input: s = "a", t = "aa"
# Output: ""
# Explanation: Both 'a's from t must be included in the window.
# Since the largest window of s only has one 'a', return empty 
# string.
# 
# Constraints:
# 
# m == s.length
# n == t.length
# 1 <= m, n <= 105
# s and t consist of uppercase and lowercase English letters.

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""
        answer = ""
        m = len(s)
        abc_count = {}
        for char in t:
            if char in abc_count:
                abc_count[char] += 1
            else:
                abc_count[char] = 1
        unique_abc = len(abc_count) 
        l, r = 0, 0
        unique_found = 0
        curr_letter_count = {}
        min_len = m + 1
        while r < m:
            char = s[r]
            if char in curr_letter_count:
                curr_letter_count[char] += 1
            else:
                curr_letter_count[char] = 1
            if char in abc_count and curr_letter_count[char] == abc_count[char]:
                unique_found += 1
            while l <= r and unique_found == unique_abc:
                char = s[l]
                if r - l + 1 < min_len:
                    min_len = r - l + 1
                    answer = s[l:r+1]
                curr_letter_count[char] -= 1
                if char in abc_count and curr_letter_count[char] < abc_count[char]:
                    unique_found -= 1
                l += 1
            r += 1
        return answer

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
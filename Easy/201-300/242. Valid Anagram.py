# 242. Valid Anagram
# 
# Given two strings s and t, return true if t is an anagram of s, and false otherwise.
# 
# An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the 
# original letters exactly once.
# 
# Example 1:
# 
# Input: s = "anagram", t = "nagaram"
# Output: true
# 
# Example 2:
# 
# Input: s = "rat", t = "car"
# Output: false
# 
# Constraints:
# 
# 1 <= s.length, t.length <= 5 * 104
# s and t consist of lowercase English letters.
# 
# Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        s_letters = [0] * 26
        t_letters = [0] * 26
        for i in s:
            s_letters[ord(i) - ord('a')] += 1
        for j in t:
            t_letters[ord(j) - ord('a')] += 1
        return s_letters == t_letters

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
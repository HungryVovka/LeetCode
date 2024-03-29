# 1347. Minimum Number of Steps to Make Two Strings Anagram
# 
# You are given two strings of the same length s and t. In one step you can choose any character of t 
# and replace it with another character.
# 
# Return the minimum number of steps to make t an anagram of s.
# 
# An Anagram of a string is a string that contains the same characters with a different (or the same) 
# ordering.
# 
# Example 1:
# Input: s = "bab", t = "aba"
# Output: 1
# Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
# 
# Example 2:
# Input: s = "leetcode", t = "practice"
# Output: 5
# Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
# 
# Example 3:
# Input: s = "anagram", t = "mangaar"
# Output: 0
# Explanation: "anagram" and "mangaar" are anagrams. 
# 
# Constraints:
# 
# 1 <= s.length <= 5 * 104
# s.length == t.length
# s and t consist of lowercase English letters only.

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        eng_abc = [0] * 26
        for a in s:
            eng_abc[ord(a) - ord('a')] += 1
        for b in t:
            eng_abc[ord(b) - ord('a')] -= 1
        return sum(abs(i) for i in eng_abc) // 2

# or

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        eng_abc = {}
        for a in s:
            if a in eng_abc:
                eng_abc[a] += 1
            else:
                eng_abc[a] = 1
        for b in t:
            if b in eng_abc:
                eng_abc[b] -= 1
            else:
                eng_abc[b] = -1
        return sum(abs(i) for i in eng_abc.values()) // 2

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
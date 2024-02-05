# 387. First Unique Character in a String
# 
# Given a string s, find the first non-repeating character in it and return its index. If it does not 
# exist, return -1.
# 
# Example 1:
# Input: s = "leetcode"
# Output: 0
# 
# Example 2:
# Input: s = "loveleetcode"
# Output: 2
# 
# Example 3:
# Input: s = "aabb"
# Output: -1
# 
# Constraints:
# 
# 1 <= s.length <= 10^5
# s consists of only lowercase English letters.

class Solution:
    def firstUniqChar(self, s: str) -> int:
        letters_count = {}
        for i in s:
            if i in letters_count:
                letters_count[i] += 1
            else:
                letters_count[i] = 1
        for j in range(len(s)):
            if letters_count[s[j]] == 1:
                return j
        return -1

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
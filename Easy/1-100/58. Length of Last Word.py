# 58. Length of Last Word
# 
# Given a string s consisting of words and spaces, return the length of the last word in the string.
# 
# A word is a maximal substring consisting of non-space characters only.
# 
# Example 1:
# Input: s = "Hello World"
# Output: 5
# Explanation: The last word is "World" with length 5.
# 
# Example 2:
# Input: s = "   fly me   to   the moon  "
# Output: 4
# Explanation: The last word is "moon" with length 4.
# 
# Example 3:
# Input: s = "luffy is still joyboy"
# Output: 6
# Explanation: The last word is "joyboy" with length 6.
# 
# Constraints:
# 
# 1 <= s.length <= 10^4
# s consists of only English letters and spaces ' '.
# There will be at least one word in s.

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.strip().split(" ")
        return len(words[-1])

# or

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.strip()
        length = 0
        for i in range(len(words) - 1, -1, -1):
            if words[i] == " ":
                break
            length += 1
        return length

# or

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.strip().split(" ")[-1])

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
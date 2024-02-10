# 647. Palindromic Substrings
# 
# Given a string s, return the number of palindromic substrings in it.
# 
# A string is a palindrome when it reads the same backward as forward.
# 
# A substring is a contiguous sequence of characters within the string.
# 
# Example 1:
# Input: s = "abc"
# Output: 3
# Explanation: Three palindromic strings: "a", "b", "c".
# 
# Example 2:
# Input: s = "aaa"
# Output: 6
# Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", 
# "aaa".
# 
# Constraints:
# 
# 1 <= s.length <= 1000
# s consists of lowercase English letters.

class Solution:   
    def countSubstrings(self, s: str) -> int:
        self.s = s
        answer: int = 0
        for i in range(len(s)):
            answer += self.palindrome_search(i, i) # odd length
            answer += self.palindrome_search(i, i + 1) # even length
        return answer
    
    def palindrome_search(self, left: int, right: int) -> int:
        count: int = 0
        while left >= 0 and right < len(self.s) \
        and self.s[left] == self.s[right]:
            count += 1
            left -= 1
            right += 1
        return count

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
# 1704. Determine if String Halves Are Alike
# 
# You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the 
# first half and b be the second half.
# 
# Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 
# 'O', 'U'). Notice that s contains uppercase and lowercase letters.
# 
# Return true if a and b are alike. Otherwise, return false.
# 
# Example 1:
# Input: s = "book"
# Output: true
# Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
# 
# Example 2:
# Input: s = "textbook"
# Output: false
# Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
# Notice that the vowel o is counted twice.
# 
# Constraints:
# 
# 2 <= s.length <= 1000
# s.length is even.
# s consists of uppercase and lowercase letters.

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = "AaEeIiOoUu"
        a_vowels, b_vowels = 0, 0
        a_length = b_length = len(s) // 2
        for a in s[:a_length]:
            if a in vowels:
                a_vowels += 1
        for b in s[b_length:]:
            if b in vowels:
                b_vowels += 1
        return a_vowels == b_vowels

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
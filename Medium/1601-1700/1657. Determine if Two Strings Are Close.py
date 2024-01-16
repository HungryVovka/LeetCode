# 1657. Determine if Two Strings Are Close
# 
# Two strings are considered close if you can attain one from the other using the following operations:
# 
# Operation 1: Swap any two existing characters.
# For example, abcde -> aecdb
# 
# Operation 2: Transform every occurrence of one existing character into another existing character, 
# and do the same with the other character.
# For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
# 
# You can use the operations on either string as many times as necessary.
# 
# Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
# 
# Example 1:
# Input: word1 = "abc", word2 = "bca"
# Output: true
# Explanation: You can attain word2 from word1 in 2 operations.
# Apply Operation 1: "abc" -> "acb"
# Apply Operation 1: "acb" -> "bca"
# 
# Example 2:
# Input: word1 = "a", word2 = "aa"
# Output: false
# Explanation: It is impossible to attain word2 from word1, or vice versa, in 
# any number of operations.
# 
# Example 3:
# Input: word1 = "cabbba", word2 = "abbccc"
# Output: true
# Explanation: You can attain word2 from word1 in 3 operations.
# Apply Operation 1: "cabbba" -> "caabbb"
# Apply Operation 2: "caabbb" -> "baaccc"
# Apply Operation 2: "baaccc" -> "abbccc"
# 
# Constraints:
# 
# 1 <= word1.length, word2.length <= 10^5
# word1 and word2 contain only lowercase English letters.

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        letters1, letters2 = {}, {}
        for i in word1:
            if i in letters1:
                letters1[i] += 1
            else:
                letters1[i] = 1
        for j in word2:
            if j in letters2:
                letters2[j] += 1
            else:
                letters2[j] = 1
        if set(letters1.keys()) != set(letters2.keys()):
            return False
        return sorted(letters1.values()) == sorted(letters2.values())

# or

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        letters1 = [0] * 26
        letters2 = [0] * 26
        for i in word1:
            letters1[ord(i) - ord('a')] += 1
        for j in word2:
            letters2[ord(j) - ord('a')] += 1
        k = 0
        while k < 26:
            if (letters1[k] == 0 and letters2[k] != 0) \
            or (letters1[k] != 0 and letters2[k] == 0):
                return False
            k += 1
        letters1.sort()
        letters2.sort()       
        return letters1 == letters2

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
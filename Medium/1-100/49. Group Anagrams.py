# 49. Group Anagrams
# 
# Given an array of strings strs, group the anagrams together. You can return the answer in 
# any order.
# 
# An Anagram is a word or phrase formed by rearranging the letters of a different word or 
# phrase, typically using all the original letters exactly once.
# 
# Example 1:
# Input: strs = ["eat","tea","tan","ate","nat","bat"]
# Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
# 
# Example 2:
# Input: strs = [""]
# Output: [[""]]
# 
# Example 3:
# Input: strs = ["a"]
# Output: [["a"]]
# 
# Constraints:
# 
# 1 <= strs.length <= 104
# 0 <= strs[i].length <= 100
# strs[i] consists of lowercase English letters.

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams_dict = {}
        for i in strs:
            i_sorted = "".join(sorted(i))
            if i_sorted in anagrams_dict:
                anagrams_dict[i_sorted].append(i)
            else:
                anagrams_dict[i_sorted] = [i]
        return list(anagrams_dict.values())

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
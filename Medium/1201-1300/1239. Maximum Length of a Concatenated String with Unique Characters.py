# 1239. Maximum Length of a Concatenated String with Unique Characters
# 
# You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of 
# arr that has unique characters.
# 
# Return the maximum possible length of s.
# 
# A subsequence is an array that can be derived from another array by deleting some or no elements 
# without changing the order of the remaining elements.
# 
# Example 1:
# Input: arr = ["un","iq","ue"]
# Output: 4
# Explanation: All the valid concatenations are:
# - ""
# - "un"
# - "iq"
# - "ue"
# - "uniq" ("un" + "iq")
# - "ique" ("iq" + "ue")
# Maximum length is 4.
# 
# Example 2:
# Input: arr = ["cha","r","act","ers"]
# Output: 6
# Explanation: Possible longest valid concatenations are "chaers" ("cha" + 
# "ers") and "acters" ("act" + "ers").
# 
# Example 3:
# Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
# Output: 26
# Explanation: The only string in arr has all 26 characters.
# 
# Constraints:
# 
# 1 <= arr.length <= 16
# 1 <= arr[i].length <= 26
# arr[i] contains only lowercase English letters.

class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def backtracking(index: int, current_path: str) -> int:
            unique_chars = set(current_path)
            max_length = len(current_path)
            for i in range(index, len(arr)):
                if len(set(arr[i])) == len(arr[i]) \
                and len(set(arr[i]).intersection(unique_chars)) == 0:
                    max_length = max(max_length, \
                    backtracking(i + 1, current_path + arr[i]))
            return max_length
        return backtracking(0, "")

# or

class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def is_unique(word: str) -> bool:
            return len(set(word)) == len(word)

        def backtracking(index: int, path: str) -> int:
            if not is_unique(path):
                return 0
            max_length = len(path)
            for i in range(index, len(arr)):
                max_length = max(max_length, backtracking(i + 1, path + arr[i]))
            return max_length

        return backtracking(0, "")

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).
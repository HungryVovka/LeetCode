// 392. Is Subsequence
//
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
// 
// A subsequence of a string is a new string that is formed from the original string by 
// deleting some (can be none) of the characters without disturbing the relative positions 
// of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
// 
// 
// Example 1:
// 
// Input: s = "abc", t = "ahbgdc"
// Output: true
// 
// Example 2:
// 
// Input: s = "axc", t = "ahbgdc"
// Output: false
//  
// 
// Constraints:
// 
// 0 <= s.length <= 100
// 0 <= t.length <= 10^4
// s and t consist only of lowercase English letters.
//  
// 
// Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 10^9, 
// and you want to check one by one to see if t has its subsequence. In this scenario, 
// how would you change your code?

#include <stdbool.h>    // bool

bool isSubsequence(char* s, char* t){
    int s_index, t_index;
    if (s == NULL || t == NULL) return false;
    s_index = 0;
    t_index = 0;
    while (t[t_index] != '\0' && s[s_index] != '\0'){
        if (t[t_index] == s[s_index]) s_index++;
        t_index++;
    }
    return (s[s_index] == '\0');
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
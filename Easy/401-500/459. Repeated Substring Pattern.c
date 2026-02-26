// 459. Repeated Substring Pattern
//
// Given a string s, check if it can be constructed by taking a substring 
// of it and appending multiple copies of the substring together.
//  
// 
// Example 1:
// 
// Input: s = "abab"
// Output: true
// Explanation: It is the substring "ab" twice.
// 
// Example 2:
// 
// Input: s = "aba"
// Output: false
// 
// Example 3:
// 
// Input: s = "abcabcabcabc"
// Output: true
// Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
//  
// 
// Constraints:
// 
// 1 <= s.length <= 10^4
// s consists of lowercase English letters.

#include <string.h>     // strlen
#include <stdbool.h>    // bool, true, false

bool repeatedSubstringPattern(char* s){
    int str_l;
    int candidate_l;
    int i;

    if (s == NULL) return false;
    str_l = strlen(s);
    for (candidate_l = 1; candidate_l <= str_l / 2; candidate_l++){
        if (str_l % candidate_l != 0) continue;
        for (i = candidate_l; i < str_l; i++){
            if (s[i] != s[i % candidate_l]) break;
        }
        if (i == str_l) return true;
    }
    return false;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
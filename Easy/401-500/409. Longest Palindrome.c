// 409. Longest Palindrome
//
// Given a string s which consists of lowercase or uppercase letters, 
// return the length of the longest palindrome that can be built with those letters.
// 
// Letters are case sensitive, for example, "Aa" is not considered a palindrome.
// 
// 
// Example 1:
// 
// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
// 
// Example 2:
// 
// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.
//  
// 
// Constraints:
// 
// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters only.

#include <string.h>     // strlen

int longestPalindrome(char* s){
    int char_frequencies[128] = {0};
    int string_l;
    int i;
    int palindrome_l = 0;
    int has_odd_char = 0;

    if (s == NULL) return 0;
    string_l = strlen(s);
    for (i = 0; i < string_l; i++){
        char_frequencies[(int)s[i]]++;
    }
    for (i = 0; i < 128; i++){
        if (char_frequencies[i] > 0){
            palindrome_l += (char_frequencies[i] / 2) * 2;
            if (char_frequencies[i] % 2 == 1) has_odd_char = 1;
        }
    }
    if (has_odd_char) palindrome_l += 1;
    return palindrome_l;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
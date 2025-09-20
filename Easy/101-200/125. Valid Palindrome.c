// 125. Valid Palindrome
// 
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
// removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// 
// Given a string s, return true if it is a palindrome, or false otherwise.
// 
// Example 1:
// 
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:
// 
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:
// 
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
// 
// Constraints:
// 
// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

#include <stdbool.h>    // bool, true, false
#include <string.h>     // strlen
#include <ctype.h>      // isalnum, tolower

bool isPalindrome(char* s){
    int left, right;
    int n;
    char c_left, c_right;

    n = strlen(s);
    left = 0;
    right = n - 1;

    while (left < right){
        // salta caratteri non alfanumerici
        while (left < right && !isalnum((unsigned char)s[left])) left++;
        while (left < right && !isalnum((unsigned char)s[right])) right--;
        c_left = tolower((unsigned char)s[left]);
        c_right = tolower((unsigned char)s[right]);
        if (c_left != c_right) return false;
        left++;
        right--;
    }
    return true;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
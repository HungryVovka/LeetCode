// 58. Length of Last Word
// 
// Given a string s consisting of words and spaces, return the length of the last word in the string.
// 
// A word is a maximal substring consisting of non-space characters only.
// 
// Example 1:
// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// 
// Example 2:
// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// 
// Example 3:
// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.
// 
// Constraints:
// 
// 1 <= s.length <= 10^4
// s consists of only English letters and spaces ' '.
// There will be at least one word in s.

#include <string.h>     // strlen

int lengthOfLastWord(char* s){
    int i;
    int length;
    int n;

    n = strlen(s);
    i = n - 1;
    length = 0;

    while (i >= 0 && s[i] == ' ') i--;
    while (i >= 0 && s[i] != ' '){
        length++;
        i--;
    }
    return length;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
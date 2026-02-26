// 434. Number of Segments in a String
//
// Given a string s, return the number of segments in the string.
// 
// A segment is defined to be a contiguous sequence of non-space characters.
// 
//  
// 
// Example 1:
// 
// Input: s = "Hello, my name is John"
// Output: 5
// Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
// 
// Example 2:
// 
// Input: s = "Hello"
// Output: 1
//  
// 
// Constraints:
// 
// 0 <= s.length <= 300
// s consists of lowercase and uppercase English letters, digits, or one of the 
// following characters "!@#$%^&*()_+-=',.:".
// 
// The only space character in s is ' '.

#include <string.h>     // strlen

int countSegments(char* s){
    int str_l;
    int i;
    int segment_count = 0;
    if (s == NULL) return 0;
    str_l = strlen(s);
    for (i = 0; i < str_l; i++){
        if (s[i] != ' '){
            if (i == 0 || s[i - 1] == ' ') segment_count++;
        }
    }
    return segment_count;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
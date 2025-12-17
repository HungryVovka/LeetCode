// 709. To Lower Case
// 
// Given a string s, return the string after replacing every uppercase letter 
// with the same lowercase letter.
// 
// 
// Example 1:
// 
// Input: s = "Hello"
// Output: "hello"
//
// Example 2:
// 
// Input: s = "here"
// Output: "here"
//
// Example 3:
// 
// Input: s = "LOVELY"
// Output: "lovely"
//  
// 
// Constraints:
// 
// 1 <= s.length <= 100
// s consists of printable ASCII characters.

#include <stdlib.h>     // malloc
#include <stddef.h>     // size_t
#include <string.h>     // strlen

char* toLowerCase(char* s){
    size_t length;
    char *answer;
    size_t i;
    char c;

    if (s == NULL){
        answer = (char *)malloc(1);
        if (answer != NULL) answer[0] = '\0';
        return answer;
    }

    length = strlen(s);
    answer = (char *)malloc(length + 1);
    if (answer == NULL) return NULL;

    for (i = 0; i < length; i++){
        c = s[i];
        if (c >= 'A' && c <= 'Z'){
            c = (char)(c + ('a' - 'A'));
        }
        answer[i] = c;
    }

    answer[length] = '\0';
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
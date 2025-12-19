// 205. Isomorphic Strings
//
// Given two strings s and t, determine if they are isomorphic.
// 
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// 
// All occurrences of a character must be replaced with another character while preserving 
// the order of characters. No two characters may map to the same character, but a character 
// may map to itself.
// 
// 
// Example 1:
// 
// Input: s = "egg", t = "add"
// 
// Output: true
// 
// Explanation:
// 
// The strings s and t can be made identical by:
// 
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// 
// Example 2:
// 
// Input: s = "foo", t = "bar"
// 
// Output: false
// 
// Explanation:
// 
// The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.
// 
// Example 3:
// 
// Input: s = "paper", t = "title"
// 
// Output: true
// 
// 
// Constraints:
// 
// 1 <= s.length <= 5 * 10^4
// t.length == s.length
// s and t consist of any valid ascii character.

#include <stddef.h>     // size_t
#include <stdbool.h>    // bool, true, false

bool isIsomorphic(char* s, char* t){
    int mapST[256];
    int mapTS[256];
    size_t i;
    unsigned char cs;
    unsigned char ct;
    if (s == NULL || t == NULL) return false;
    for (i = 0; i < 256; i++){
        mapST[i] = -1;
        mapTS[i] = -1;
    }
    i = 0;
    while (s[i] != '\0' && t[i] != '\0'){
        cs = (unsigned char)s[i];
        ct = (unsigned char)t[i];
        if (mapST[cs] != -1){
            if (mapST[cs] != (int)ct) return false;
        } else {
            mapST[cs] = (int)ct;
        }
        if (mapTS[ct] != -1){
            if (mapTS[ct] != (int)cs) return false;
        } else {
            mapTS[ct] = (int)cs;
        }
        i++;
    }
    return (s[i] == '\0' && t[i] == '\0');
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
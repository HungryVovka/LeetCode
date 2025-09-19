// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
// 
// If there is no common prefix, return an empty string "".
// 
// Example 1:
// 
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:
// 
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//  
// 
// Constraints:
// 
// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters if it is non-empty.

#include <string.h> // strlen, strncpy
#include <stdlib.h> // malloc

char* longestCommonPrefix(char** strs, int strs_size){
    int i, j;
    int prefix_length;
    int current_length;
    char *prefix;

    if (strs_size == 0){
        prefix = (char*)malloc(1);      // 1 byte per stringa vuota
        prefix[0] = '\0';               // solo terminatore '\0'
        return prefix;
    }

    prefix_length = strlen(strs[0]);    // prefissp iniziale = prima stringa
    for (i = 1; i < strs_size; i++){
        current_length = 0;             // lunghezza comune corrente
        for (j = 0; j < prefix_length && strs[i][j] != '\0'; j++){
            if (strs[0][j] != strs[i][j]) break;    // caratteri diversi -> stop
            current_length++;           // carattero uguali
        }
        prefix_length = current_length; // aggiorna prefisso comune
        if (prefix_length == 0) break;  // se prefisso vuoto uscita immediata
    }

    prefix = (char*)malloc(prefix_length + 1);  // +1 per terminatore '\0'
    strncpy(prefix, strs[0], prefix_length);    // copia il prefisso
    prefix[prefix_length] = '\0';               // chiudi la stringa
    return prefix;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
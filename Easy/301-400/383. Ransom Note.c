// 383. Ransom Note
//
// Given two strings ransomNote and magazine, return true if ransomNote can be 
// constructed by using the letters from magazine and false otherwise.
// 
// Each letter in magazine can only be used once in ransomNote.
// 
// 
// Example 1:
// 
// Input: ransomNote = "a", magazine = "b"
// Output: false
// 
// Example 2:
// 
// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// 
// Example 3:
// 
// Input: ransomNote = "aa", magazine = "aab"
// Output: true
//  
// 
// Constraints:
// 
// 1 <= ransomNote.length, magazine.length <= 10^5
// ransomNote and magazine consist of lowercase English letters.

#include <stdbool.h>        // bool

bool canConstruct(char* ransomNote, char* magazine){
    int letter_counts[26];
    int index;
    int letter_index;
    if (ransomNote == NULL || magazine == NULL) return false;
    for (index = 0; index < 26; index++) letter_counts[index] = 0;
    index = 0;
    while (magazine[index] != '\0'){
        letter_index = (int)(magazine[index] - 'a');
        if (letter_index < 0 || letter_index >= 26) return false;
        letter_counts[letter_index]++;
        index++;
    }
    index = 0;
    while (ransomNote[index] != '\0'){
        letter_index = (int)(ransomNote[index] - 'a');
        if (letter_index < 0 || letter_index >= 26) return false;
        letter_counts[letter_index]--;
        if (letter_counts[letter_index] < 0) return false;
        index++;
    }
    return true;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
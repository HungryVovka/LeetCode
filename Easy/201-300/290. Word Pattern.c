// 290. Word Pattern
//
// Given a pattern and a string s, find if s follows the same pattern.
// 
// Here follow means a full match, such that there is a bijection between a letter in 
// pattern and a non-empty word in s. Specifically:
// 
// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.
//  
// 
// Example 1:
// 
// Input: pattern = "abba", s = "dog cat cat dog"
// 
// Output: true
// 
// Explanation:
// 
// The bijection can be established as:
// 
// 'a' maps to "dog".
// 'b' maps to "cat".
// 
// Example 2:
// 
// Input: pattern = "abba", s = "dog cat cat fish"
// 
// Output: false
// 
// Example 3:
// 
// Input: pattern = "aaaa", s = "dog cat cat dog"
// 
// Output: false
// 
//  
// 
// Constraints:
// 
// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.

#include <stdbool.h>        // bool
#include <string.h>         // strlen

struct WordRef {
    const char *start;
    int len;
};

static bool word_equals(const char *startA, int lenA, const char *startB, int lenB){
    int i;
    if (lenA != lenB) return false;
    for (i = 0; i < lenA; i++){
        if (startA[i] != startB[i]) return false;
    }
    return true;
}


bool wordPattern(char* pattern, char* s){
    struct WordRef letter_to_word[26];
    struct WordRef seen_words[300];
    char seen_letter[300];
    int i, j;
    int pattern_len;
    int s_pos;
    int words_count;
    int letter_index;
    const char *word_start;
    int word_len;

    if (pattern == NULL || s == NULL) return false;
    for (i = 0; i < 26; i++){
        letter_to_word[i].start = NULL;
        letter_to_word[i].len = 0;
    }
    pattern_len = (int)strlen(pattern);
    s_pos = 0;
    words_count = 0;

    for (i = 0; i < pattern_len; i++){
        if (s[s_pos] == '\0') return false;
        word_start = s + s_pos;
        word_len = 0;
        while (s[s_pos] != '\0' && s[s_pos] != ' '){
            word_len++;
            s_pos++;
        }
        if (s[s_pos] == ' ') s_pos++;
        letter_index = (int)(pattern[i] - 'a');
        if (letter_index < 0 || letter_index >= 26) return false;
        if (letter_to_word[letter_index].start != NULL){
            if (!word_equals(letter_to_word[letter_index].start, 
            letter_to_word[letter_index].len, word_start, word_len)){
                return false;
            }
            continue;
        }
        for (j = 0; j < words_count; j++){
            if (word_equals(seen_words[j].start, 
            seen_words[j].len, word_start, word_len)){
                return (seen_letter[j] == pattern[i]);
            }
        }
        seen_words[words_count].start = word_start;
        seen_words[words_count].len = word_len;
        seen_letter[words_count] = pattern[i];
        words_count++;
        letter_to_word[letter_index].start = word_start;
        letter_to_word[letter_index].len = word_len;
    }
    return s[s_pos] == '\0';
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
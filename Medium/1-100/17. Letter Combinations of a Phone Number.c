// 17. Letter Combinations of a Phone Number
//
// Given a string containing digits from 2-9 inclusive, return 
// all possible letter combinations that the number could represent. 
// Return the answer in any order.
// 
// A mapping of digits to letters (just like on the telephone buttons) 
// is given below. Note that 1 does not map to any letters.
// 
// Example 1:
// 
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:
// 
// Input: digits = "2"
// Output: ["a","b","c"]
//  
// 
// Constraints:
// 
// 1 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

#include <stdlib.h>     // malloc, free
#include <string.h>     // strlen

static const char *digit_to_letters[10] = {
    "",         // 0
    "",         // 1
    "abc",      // 2
    "def",      // 3
    "ghi",      // 4
    "jkl",      // 5
    "mno",      // 6
    "pqrs",     // 7
    "tuv",      // 8
    "wxyz"      // 9
};

static void generateCombinations(
    char* digits,
    int current_i,
    int digits_l,
    char* current_comb,
    char** result_array,
    int* result_i
){
    int letter_i;
    int letters_count;
    const char* letters;
    if (current_i == digits_l){
        current_comb[digits_l] = '\0';
        strcpy(result_array[*result_i], current_comb);
        (*result_i)++;
        return;
    }
    letters = digit_to_letters[digits[current_i] - '0'];
    letters_count = strlen(letters);
    for (letter_i = 0; letter_i < letters_count; letter_i++){
        current_comb[current_i] = letters[letter_i];
        generateCombinations(
            digits,
            current_i + 1,
            digits_l,
            current_comb,
            result_array,
            result_i
        );
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize){
    int digits_l;
    int total_comb = 1;
    int i;
    int result_i = 0;
    char** result_array;
    char* current_comb;
    if (digits == NULL || digits[0] == '\0'){
        *returnSize = 0;
        return NULL;
    }
    digits_l = strlen(digits);
    for (i = 0; i < digits_l; i++){
        total_comb *= strlen(digit_to_letters[digits[i] - '0']);
    }
    result_array = (char**)malloc(total_comb * sizeof(char*));
    current_comb = (char*)malloc((digits_l + 1) * sizeof(char));
    for (i = 0; i < total_comb; i++){
        result_array[i] = (char*)malloc((digits_l + 1) * sizeof(char));
    }
    generateCombinations(
        digits,
        0,
        digits_l,
        current_comb,
        result_array,
        &result_i
    );
    free(current_comb);
    *returnSize = total_comb;
    return result_array;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
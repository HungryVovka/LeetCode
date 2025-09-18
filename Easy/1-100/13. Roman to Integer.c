// 13. Roman to Integer
// 
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// 
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// 
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply 
// X + II. The number 27 is written as XXVII, which is XX + V + II.
// 
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
// Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same 
// principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
// 
// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.
// 
// Example 1:
// 
// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// 
// Example 2:
// 
// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// 
// Example 3:
// 
// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
// 
// Constraints:
// 
// 1 <= s.length <= 15
// s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
// It is guaranteed that s is a valid roman numeral in the range [1, 3999].

#include <string.h>     // strlen, strncmp

int romanToInt(char* s){
    const char* roman[] = {
        "CM", "CD", "XC", "XL", "IX", "IV",
        "M", "D", "C", "L", "X", "V", "I"
    };
    const int values[] = {
        900, 400, 90, 40, 9, 4,
        1000, 500, 100, 50, 10, 5, 1
    };

    int i, j;
    int num;
    int length;
    int matched;
    int sym_len;

    i = 0;
    num = 0;
    length = strlen(s);

    while (i < length){
        matched = 0;
        for (j = 0; j < 13; j++){
            sym_len = strlen(roman[j]);
            if (i + sym_len <= length && strncmp(s + i, roman[j], sym_len) == 0){
                num += values[j];
                i += sym_len;
                matched = 1;
                break;
            }
        }
        if (!matched){
            i++;
        }
    }
    return num;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
// 405. Convert a Number to Hexadecimal
// 
// Given a 32-bit integer num, return a string representing its hexadecimal 
// representation. For negative integers, two’s complement method is used.
// 
// All the letters in the answer string should be lowercase characters, and 
// there should not be any leading zeros in the answer except for the zero itself.
// 
// Note: You are not allowed to use any built-in library method to directly 
// solve this problem.
// 
// 
// Example 1:
// 
// Input: num = 26
// Output: "1a"
// 
// Example 2:
// 
// Input: num = -1
// Output: "ffffffff"
//  
// 
// Constraints:
// 
// -2^31 <= num <= 2^31 - 1

#include <stdlib.h>         // malloc
#include <stddef.h>         // size_t

char* toHex(int num){
    unsigned int value;
    char buffer[9];
    const char hexDigits[] = "0123456789abcdef";
    int index;
    int started;
    int shift;
    int nibble;
    int i;
    char *answer;

    value = (unsigned int)num;

    if (value == 0){
        answer = (char *)malloc(2);
        if (answer != NULL){
            answer[0] = '0';
            answer[1] = '\0';
        }
        return answer;
    }

    index = 0;
    started = 0;

    for (shift = 28; shift >= 0; shift -= 4){
        nibble = (int)((value >> shift) & 0xF);
        if (nibble != 0 || started){
            buffer[index++] = hexDigits[nibble];
            started = 1;
        }
    }
    buffer[index] = '\0';
    answer = (char *)malloc((size_t)index + 1);
    if (answer == NULL) return NULL;
    for (i = 0; i <= index; i++){
        answer[i] = buffer[i];
    }
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
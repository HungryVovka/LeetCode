// 415. Add Strings
// 
// Given two non-negative integers, num1 and num2 represented as string, 
// return the sum of num1 and num2 as a string.
// 
// You must solve the problem without using any built-in library for 
// handling large integers (such as BigInteger). You must also not convert 
// the inputs to integers directly.
// 
// 
// Example 1:
// 
// Input: num1 = "11", num2 = "123"
// Output: "134"
// 
// Example 2:
// 
// Input: num1 = "456", num2 = "77"
// Output: "533"
// 
// Example 3:
// 
// Input: num1 = "0", num2 = "0"
// Output: "0"
//  
// 
// Constraints:
// 
// 1 <= num1.length, num2.length <= 10^4
// num1 and num2 consist of only digits.
// num1 and num2 don't have any leading zeros except for the zero itself.

#include <stdlib.h>     // malloc, free
#include <stddef.h>     // size_t
#include <string.h>     // strlen

char* addStrings(char* num1, char* num2){
    size_t len1, len2, maxLen;
    char *buffer;
    char *answer;
    size_t index1, index2, writePos;
    int carry;
    int digitSum;
    size_t i;
    size_t outLen;

    if (num1 == NULL || num2 == NULL){
        answer = (char *)malloc(1);
        if (answer != NULL) answer[0] = '\0';
        return answer;
    }

    len1 = strlen(num1);
    len2 = strlen(num2);
    maxLen = (len1 > len2) ? len1 : len2;
    buffer = (char *)malloc(maxLen + 2);
    if (buffer == NULL) return NULL;
    index1 = len1;
    index2 = len2;
    writePos = maxLen + 1;
    buffer[writePos] = '\0';
    carry = 0;
    while (index1 > 0 || index2 > 0 || carry != 0){
        digitSum = carry;
        if (index1 > 0){
            index1--;
            digitSum += (int)(num1[index1] - '0');
        }
        if (index2 > 0){
            index2--;
            digitSum += (int)(num2[index2] - '0');
        }
        carry = digitSum / 10;
        writePos--;
        buffer[writePos] = (char)('0' + (digitSum % 10));
    }
    outLen = (maxLen + 2) - writePos;
    answer = (char *)malloc(outLen);
    if (answer == NULL){
        free(buffer);
        return NULL;
    }
    for (i = 0; i< outLen; i++){
        answer[i] = buffer[writePos + i];
    }
    free(buffer);
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
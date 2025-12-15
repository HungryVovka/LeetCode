// 43. Multiply Strings
//
// Given two non-negative integers num1 and num2 represented as strings, 
// return the product of num1 and num2, also represented as a string.
// 
// Note: You must not use any built-in BigInteger library or convert the 
// inputs to integer directly.
// 
// 
// Example 1:
// 
// Input: num1 = "2", num2 = "3"
// Output: "6"
// 
// Example 2:
// 
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//  
// 
// Constraints:
// 
// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.

#include <stdlib.h>     // malloc, free
#include <string.h>     // strlen

char* multiply(char* num1, char* num2){
    size_t len1, len2, resultLen;
    int *digits;
    size_t i, j;

    int digit1, digit2;
    int carry;
    int sumValue;

    size_t firstNonZero;
    size_t outLen;
    char *outString;

    if (num1 == NULL || num2 == NULL){
        outString = (char *)malloc(1);
        if (outString != NULL) outString[0] = '\0';
        return outString;
    }

    if ((num1[0] == '0' && num1[1] == '\0') || (num2[0] == '0' && num2[1] == '\0')){
        outString = (char *)malloc(2);
        if (outString != NULL){
            outString[0] = '0';
            outString[1] = '\0';
        }
        return outString;
    }

    len1 = strlen(num1);
    len2 = strlen(num2);
    resultLen = len1 + len2;

    digits = (int *)malloc(resultLen * sizeof(int));
    if (digits == NULL) return NULL;
    for (i = 0; i < resultLen; i++) digits[i] = 0;

    for (i = len1; i > 0; i--){
        digit1 = num1[i - 1] - '0';
        carry = 0;
        for (j = len2; j > 0; j--){
            digit2 = num2[j - 1] - '0';
            sumValue = digits[(i - 1) + (j - 1) + 1] + digit1 * digit2 + carry;
            digits[(i - 1) + (j - 1) + 1] = sumValue % 10;
            carry = sumValue / 10;
        }
        digits[(i - 1)] += carry;
    }
    firstNonZero = 0;
    while (firstNonZero < resultLen && digits[firstNonZero] == 0) firstNonZero++;
    if (firstNonZero == resultLen){
        free(digits);
        outString = (char *)malloc(2);
        if (outString != NULL){
            outString[0] = '0';
            outString[1] = '\0';
        }
        return outString;
    }
    outLen = resultLen - firstNonZero;
    outString = (char *)malloc(outLen + 1);
    if (outString == NULL){
        free(digits);
        return NULL;
    }
    for (i = 0; i < outLen; i++){
        outString[i] = (char)('0' + digits[firstNonZero + i]);
    }
    outString[outLen] = '\0';
    free(digits);
    return outString;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
// 67. Add Binary
// 
// Given two binary strings a and b, return their sum as a binary string.
// 
// Example 1:
// 
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
// 
// Input: a = "1010", b = "1011"
// Output: "10101"
// 
// Constraints:
// 
// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

#include <string.h>     // strlen, memmove
#include <stdlib.h>     // malloc


char* addBinary(char* a, char* b) {
    int i, j, k;
    int carry;
    int sum;
    int len_a, len_b, max_len;

    len_a = strlen(a);
    len_b = strlen(b);
    max_len = (len_a > len_b ? len_a : len_b) + 1;  // +1 per eventuale carry

    char *result = (char*)malloc(sizeof(char) * (max_len + 1));

    i = len_a - 1;      // indice per a
    j = len_b - 1;      // indice per b
    k = max_len;        // indice per result (costruiamo da fine)
    result[k] = '\0';   // terminatore stringa
    carry = 0;

    while (i >= 0 || j >= 0 || carry > 0){
        sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result[--k] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (k > 0) memmove(result, result + k, max_len - k + 1);
    return result;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
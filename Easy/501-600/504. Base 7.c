// 504. Base 7
//
// Given an integer num, return a string of its base 7 representation.
// 
// 
// Example 1:
// 
// Input: num = 100
// Output: "202"
// 
// Example 2:
// 
// Input: num = -7
// Output: "-10"
//  
// 
// Constraints:
// 
// -10^7 <= num <= 10^7

#include <stdlib.h>     // malloc
#include <stdbool.h>    // bool

char* convertToBase7(int num){
    char *answer;
    int i;
    int value;
    int left, right, temp;
    bool is_negative;
    answer = (char *)malloc(13 * sizeof(char)); // 11 num + '\0'
    if (answer == NULL) return NULL;
    if (num == 0){
        answer[0] = '0';
        answer[1] = '\0';
        return answer;
    }
    is_negative = (num < 0);
    value = is_negative ? -num : num;
    i = 0;
    while (value > 0){
        answer[i++] = (char)('0' + (value % 7));
        value /= 7;
    }
    if (is_negative) answer[i++] = '-';
    answer[i] = '\0';

    left = 0;
    right = i - 1;
    while (left < right){
        temp = answer[left];
        answer[left] = answer[right];
        answer[right] = temp;
        left++;
        right--;
    }
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
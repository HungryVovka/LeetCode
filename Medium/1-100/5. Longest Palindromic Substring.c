// 5. Longest Palindromic Substring
//
// Given a string s, return the longest palindromic substring in s.
// 
// 
// Example 1:
// 
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// 
// Example 2:
// 
// Input: s = "cbbd"
// Output: "bb"
//  
// 
// Constraints:
// 
// 1 <= s.length <= 1000
// s consist of only digits and English letters.

#include <stdlib.h>     // malloc, free
#include <string.h>     // strlen, memcpy

char* longestPalindrome(char* s){
    size_t originalLength;
    size_t transformedLength;
    char *transformed;
    int *palRadius;
    size_t i;
    int center;
    int rightBoundary;
    int mirror;
    int maxLen;
    int centerIndex;
    size_t startIndex;
    char *answer;

    if (s == NULL){
        answer = (char *)malloc(1);
        if (answer != NULL) answer[0] = '\0';
        return answer;
    }

    originalLength = strlen(s);
    if (originalLength == 0){
        answer = (char *)malloc(1);
        if (answer != NULL) answer[0] = '\0';
        return answer;
    }

    transformedLength = 2 * originalLength + 3;
    transformed = (char *)malloc(transformedLength);
    if (transformed == NULL) return NULL;

    palRadius = (int *)malloc(transformedLength * sizeof(int));
    if (palRadius == NULL){
        free(transformed);
        return NULL;
    }

    transformed[0] = '^';
    transformed[transformedLength - 1] = '$';

    for (i = 0; i < transformedLength - 2; i++){
        if ((i % 2) == 0){
            transformed[i + 1] = '#';
        } else {
            transformed[i + 1] = s[i / 2];
        }
    }

    for (i = 0; i < transformedLength; i++) palRadius[i] = 0;

    center = 0;
    rightBoundary = 0;
    maxLen = 0;
    centerIndex = 0;

    for (i = 1; i < transformedLength - 1; i++){
        if (rightBoundary > (int)i){
            mirror = 2 * center - (int)i;
            palRadius[i] = palRadius[mirror];
            if (palRadius[i] > rightBoundary - (int)i) palRadius[i] = rightBoundary - (int)i;
        } else {
            palRadius[i] = 0;
        }

        while (transformed[i + 1 + (size_t)palRadius[i]] == transformed[i - 1 - (size_t)palRadius[i]]){
            palRadius[i]++;
        }
        if ((int)i + palRadius[i] > rightBoundary){
            center = (int)i;
            rightBoundary = (int)i + palRadius[i];
        }
        if (palRadius[i] > maxLen){
            maxLen = palRadius[i];
            centerIndex = (int)i;
        }
    }

    startIndex = (size_t)((centerIndex - maxLen) / 2);
    answer = (char *)malloc((size_t)maxLen + 1);
    if (answer == NULL){
        free(palRadius);
        free(transformed);
        return NULL;
    }

    memcpy(answer, s + startIndex, (size_t)maxLen);
    answer[maxLen] = '\0';
    free(palRadius);
    free(transformed);
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
// 412. Fizz Buzz
// 
// Given an integer n, return a string array answer (1-indexed) where:
// 
// answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
// answer[i] == "Fizz" if i is divisible by 3.
// answer[i] == "Buzz" if i is divisible by 5.
// answer[i] == i (as a string) if none of the above conditions are true.
//  
// 
// Example 1:
// 
// Input: n = 3
// Output: ["1","2","Fizz"]
// 
// Example 2:
// 
// Input: n = 5
// Output: ["1","2","Fizz","4","Buzz"]
// 
// Example 3:
// 
// Input: n = 15
// Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
//  
// 
// Constraints:
// 
// 1 <= n <= 10^4

#include <stdlib.h>         // malloc, free
#include <stddef.h>         // size_t
#include <stdio.h>          // sprintf
#include <string.h>         // strlen

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** fizzBuzz(int n, int* returnSize){
    char **answer;
    int currentNumber;
    int answerIndex;
    int cleanupIndex;
    char buffer[16];

    if (returnSize != NULL) *returnSize = 0;
    if (n <= 0 || returnSize == NULL) return NULL;
    answer = (char **)malloc((size_t)n * sizeof(char *));
    if (answer == NULL) return NULL;
    answerIndex = 0;
    for (currentNumber = 1; currentNumber <= n; currentNumber++){
        if (currentNumber % 15 == 0){
            answer[answerIndex] = (char *)malloc(9);    // "FizzBuzz" + '\0'
            if (answer[answerIndex] == NULL) goto cleanup;
            answer[answerIndex][0] = 'F';
            answer[answerIndex][1] = 'i';
            answer[answerIndex][2] = 'z';
            answer[answerIndex][3] = 'z';
            answer[answerIndex][4] = 'B';
            answer[answerIndex][5] = 'u';
            answer[answerIndex][6] = 'z';
            answer[answerIndex][7] = 'z';
            answer[answerIndex][8] = '\0';
        } else if (currentNumber % 3 == 0){
            answer[answerIndex] = (char *)malloc(5);    // "Fizz" + '\0'
            if (answer[answerIndex] == NULL) goto cleanup;
            answer[answerIndex][0] = 'F';
            answer[answerIndex][1] = 'i';
            answer[answerIndex][2] = 'z';
            answer[answerIndex][3] = 'z';
            answer[answerIndex][4] = '\0';
        } else if (currentNumber % 5 == 0){
            answer[answerIndex] = (char *)malloc(5);    // "Buzz" + '\0'
            if (answer[answerIndex] == NULL) goto cleanup;
            answer[answerIndex][0] = 'B';
            answer[answerIndex][1] = 'u';
            answer[answerIndex][2] = 'z';
            answer[answerIndex][3] = 'z';
            answer[answerIndex][4] = '\0';
        } else {
            int copyIndex;
            sprintf(buffer, "%d", currentNumber);
            answer[answerIndex] = (char *)malloc((size_t)strlen(buffer) + 1);
            if (answer[answerIndex] == NULL) goto cleanup;
            for (copyIndex = 0; buffer[copyIndex] != '\0'; copyIndex++){
                answer[answerIndex][copyIndex] = buffer[copyIndex];
            }
            answer[answerIndex][copyIndex] = '\0';
        }
        answerIndex++;
    }
    *returnSize = n;
    return answer;

    cleanup:
        for (cleanupIndex = 0; cleanupIndex < answerIndex; cleanupIndex++){
            free(answer[cleanupIndex]);
        }
        free(answer);
        return NULL;
}

// or

#include <stdlib.h>         // malloc, free
#include <stddef.h>         // size_t
#include <stdio.h>          // sprintf, snprintf
#include <string.h>         // strlen

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static char *makeCopyLiteral(const char *text, size_t len){
    char *p;
    size_t i;
    p = (char *)malloc(len + 1);
    if (p == NULL) return NULL;
    for (i = 0; i < len; i++){
        p[i] = text[i];
    }
    p[len] = '\0';
    return p;
}

char** fizzBuzz(int n, int* returnSize){
    char **answer;
    int currentNumber;
    int answerIndex;
    int cleanupIndex;

    if (returnSize != NULL) *returnSize = 0;
    if (n <= 0 || returnSize == NULL) return NULL;
    answer = (char **)malloc((size_t)n * sizeof(char *));
    if (answer == NULL) return NULL;
    answerIndex = 0;
    for (currentNumber = 1; currentNumber <= n; currentNumber++){
        if (currentNumber % 15 == 0){
            answer[answerIndex] = makeCopyLiteral("FizzBuzz", 8);
            if (answer[answerIndex] == NULL) goto cleanup;
        } else if (currentNumber % 3 == 0){
            answer[answerIndex] = makeCopyLiteral("Fizz", 4);
            if (answer[answerIndex] == NULL) goto cleanup;
        } else if (currentNumber % 5 == 0){
            answer[answerIndex] = makeCopyLiteral("Buzz", 4);
            if (answer[answerIndex] == NULL) goto cleanup;

        } else {
            int neededLen;
            char *p;
            neededLen = snprintf(NULL, 0, "%d", currentNumber);
            if (neededLen < 0) goto cleanup;
            p = (char *)malloc((size_t)neededLen + 1);
            if (p == NULL) goto cleanup;
            sprintf(p, "%d", currentNumber);
            answer[answerIndex] = p;
        }
        answerIndex++;
    }
    *returnSize = n;
    return answer;

    cleanup:
        for (cleanupIndex = 0; cleanupIndex < answerIndex; cleanupIndex++){
            free(answer[cleanupIndex]);
        }
        free(answer);
        return NULL;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
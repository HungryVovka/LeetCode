// 168. Excel Sheet Column Title
// 
// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
// 
// For example:
// 
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
//  
// Example 1:
// 
// Input: columnNumber = 1
// Output: "A"
// 
// Example 2:
// 
// Input: columnNumber = 28
// Output: "AB"
// 
// Example 3:
// 
// Input: columnNumber = 701
// Output: "ZY"

#include <stdlib.h>    // malloc
#include <string.h>    // strlen

char* convertToTitle(int column_number){
    char *answer;
    int i;
    int index;
    int length;
    answer = (char*)malloc(sizeof(char) * 16);  // massimo 8 caratteri + terminatore
    i = 0;

    while (column_number > 0){
        index = (column_number - 1) % 26;
        answer[i++] = (char)(index + 'A');      // aggiungi lettera
        column_number = (column_number - 1) / 26;
    }
    answer[i] = '\0';                           // terminatore stringa
    length = i;                                 // inverti la stringa (perché è al contrario)
    for (i = 0; i < length / 2; i++){
        char swap = answer[i];
        answer[i] = answer[length - 1 - i];
        answer[length - 1 - i] = swap;
    }
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
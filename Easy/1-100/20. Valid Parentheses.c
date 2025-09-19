// 20. Valid Parentheses
// 
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// 
// An input string is valid if:
// 
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// 
// Example 1:
// 
// Input: s = "()"
// Output: true
// 
// Example 2:
// 
// Input: s = "()[]{}"
// Output: true
// 
// Example 3:
// 
// Input: s = "(]"
// Output: false
//  
// Constraints:
// 
// 1 <= s.length <= 10^4
// s consists of parentheses only '()[]{}'.

#include <stdbool.h>    // bool, true, false
#include <string.h>     // strlen

bool isValid(char* s){
    int n;
    int i;
    int top;
    char stack[10005];  // pila per parentesi
    char c;

    n = strlen(s);
    top = -1;           // indice della cima della pila

    for (i = 0; i < n; i++){
        c = s[i];
        if (c == '(' || c == '[' || c == '{'){
            stack[++top] = c;   // push nella pila
        } else {
            if (top == -1) return false;      // se pila vuota -> parentesi chiusa senza apertura
            if ((c == ')' && stack[top] != '(') ||
                (c == ']' && stack[top] != '[') ||
                (c == '}' && stack[top] != '{'))
                return false;
            top--;                           // pop dalla pila
        }
    }
    return top == -1;   // se pila vuota alla fine -> tutto valido
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
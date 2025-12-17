// 155. Min Stack
// 
// Design a stack that supports push, pop, top, and retrieving the minimum 
// element in constant time.
// 
// Implement the MinStack class:
// 
// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// 
// You must implement a solution with O(1) time complexity for each function.
// 
//  
// Example 1:
// 
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
// 
// Output
// [null,null,null,null,-3,null,0,-2]
// 
// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
//  
// 
// Constraints:
// 
// -2^31 <= val <= 2^31 - 1
// Methods pop, top and getMin operations will always be called on 
// non-empty stacks.
// At most 3 * 10^4 calls will be made to push, pop, top, and getMin.

#include <stdlib.h>         // malloc, free
#include <stddef.h>         // size_t

typedef struct MinStackNode {
    int value;
    int minSoFar;
    struct MinStackNode *next;
} MinStackNode;

typedef struct {
    MinStackNode *topNode;
} MinStack;


MinStack* minStackCreate(){
    MinStack *stack;
    stack = (MinStack *)malloc(sizeof(MinStack));
    if (stack == NULL) return NULL;
    stack->topNode = NULL;
    return stack;
}

void minStackPush(MinStack* obj, int val){
    MinStackNode *node;
    int currentMin;
    if (obj == NULL) return;
    node = (MinStackNode *)malloc(sizeof(MinStackNode));
    if (node == NULL) return;
    if (obj->topNode == NULL){
        currentMin = val;
    } else {
        currentMin = obj->topNode->minSoFar;
        if (val < currentMin) currentMin = val;
    }
    node->value = val;
    node->minSoFar = currentMin;
    node->next = obj->topNode;
    obj->topNode = node;
}

void minStackPop(MinStack* obj){
    MinStackNode *toDelete;
    if (obj == NULL || obj->topNode == NULL) return;
    toDelete = obj->topNode;
    obj->topNode = obj->topNode->next;
    free(toDelete);
}

int minStackTop(MinStack* obj){
    return obj->topNode->value;
}

int minStackGetMin(MinStack* obj) {
    return obj->topNode->minSoFar;
}

void minStackFree(MinStack* obj){
    MinStackNode *current;
    MinStackNode *next;
    if (obj == NULL) return;
    current = obj->topNode;
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
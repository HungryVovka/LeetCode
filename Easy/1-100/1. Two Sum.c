// 1. Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// 
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// 
// You can return the answer in any order.
// 
//  
// 
// Example 1:
// 
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// 
// Example 2:
// 
// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// 
// Example 3:
// 
// Input: nums = [3,3], target = 6
// Output: [0,1]
//  
// 
// Constraints:
// 
// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// 
// Only one valid answer exists.
// 
// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

#include <stdlib.h> // malloc

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* numeri, int dimensione, 
            int obiettivo, int* dimensione_ritorno){
    int i, j;
    int* risultato;

    for (i = 0; i < dimensione; i++){
        for (j = i + 1; j < dimensione; j++){
            if (numeri[i] + numeri[j] == obiettivo){
                risultato = (int*)malloc(2 * sizeof(int));
                risultato[0] = i;
                risultato[1] = j;
                *dimensione_ritorno = 2;
                return risultato;
            }
        }
    }
    *dimensione_ritorno = 0;
    return NULL;
}

// or

#include <stdlib.h>         // malloc, free
#include <stddef.h>         // size_t

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define HASH_SIZE 10007

struct HashNode {
    int value;
    int index;
    struct HashNode *next;
};

static size_t hashFunction(int value){
    unsigned int uvalue;
    uvalue = (unsigned int)value;
    return (size_t)(uvalue % HASH_SIZE);
}

static struct HashNode* hashFind(struct HashNode **table, int value){
    size_t bucket;
    struct HashNode *current;
    bucket = hashFunction(value);
    current = table[bucket];
    while (current != NULL){
        if (current->value == value) return current;
        current = current->next;
    }
    return NULL;
}

static int hashInsert(struct HashNode **table, int value, int index){
    size_t bucket;
    struct HashNode *node;
    bucket = hashFunction(value);
    node = (struct HashNode *)malloc(sizeof(struct HashNode));
    if (node == NULL) return 0;

    node->value = value;
    node->index = index;
    node->next = table[bucket];
    table[bucket] = node;
    return 1;
}

static void hashFree(struct HashNode **table){
    size_t i;
    struct HashNode *current;
    struct HashNode *next;
    for (i = 0; i < HASH_SIZE; i++){
        current = table[i];
        while (current != NULL){
            next = current->next;
            free(current);
            current = next;
        }
        table[i] = NULL;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    struct HashNode * hashTable[HASH_SIZE];
    int i;
    int needed;
    struct HashNode *found;
    int *result;

    if (returnSize != NULL) *returnSize = 0;

    if (nums == NULL || numsSize < 2 || returnSize == NULL){
        return NULL;
    }

    for (i = 0; i < HASH_SIZE; i++){
        hashTable[i] = NULL;
    }

    for (i = 0; i < numsSize; i++){
        needed = target - nums[i];
        found = hashFind(hashTable, needed);
        if (found != NULL){
            result = (int *)malloc(2 * sizeof(int));
            if (result == NULL){
                hashFree(hashTable);
                return NULL;
            }
            result[0] = found->index;
            result[1] = i;
            *returnSize = 2;
            hashFree(hashTable);
            return result;
        }
        if (!hashInsert(hashTable, nums[i], i)){
            hashFree(hashTable);
            return NULL;
        }
    }
    hashFree(hashTable);
    return NULL;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
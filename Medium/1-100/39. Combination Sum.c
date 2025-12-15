// 39. Combination Sum
//
// Given an array of distinct integers candidates and a target integer target, 
// return a list of all unique combinations of candidates where the chosen 
// numbers sum to target. You may return the combinations in any order.
// 
// The same number may be chosen from candidates an unlimited number of times. 
// Two combinations are unique if the frequency of at least one of the chosen 
// numbers is different.
// 
// The test cases are generated such that the number of unique combinations 
// that sum up to target is less than 150 combinations for the given input.
// 
// 
// Example 1:
// 
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// 
// Example 2:
// 
// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:
// 
// Input: candidates = [2], target = 1
// Output: []
//  
// 
// Constraints:
// 
// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40

#include <stdlib.h>     // qsort, malloc, realloc, free
#include <string.h>     // memcpy
#include <stddef.h>     // size_t

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct ResultCollector {
    int **rows;
    int *colSizes;
    int count;
    int capacity;
};

static int compareIntAsc(const void *a, const void *b){
    int x, y;
    x = *(const int *)a;
    y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static int ensureCapacity(struct ResultCollector *collector){
    int newCapacity;
    int **newRows;
    int *newColSizes;

    if (collector->count < collector->capacity) return 1;
    newCapacity = collector->capacity * 2;
    if (newCapacity < 16) newCapacity = 16;
    newRows = (int**)realloc(collector->rows, (size_t)newCapacity * sizeof(int*));
    if (newRows == NULL) return 0;
    newColSizes = (int*)realloc(collector->colSizes, (size_t)newCapacity * sizeof(int));
    if (newColSizes == NULL){
        collector->rows = (int **)realloc(newRows, (size_t)collector->capacity * sizeof(int *));
        return 0;
    }
    collector->rows = newRows;
    collector->colSizes = newColSizes;
    collector->capacity = newCapacity;
    return 1;
}

static int pushCombination(struct ResultCollector *collector, const int *path, int pathLen){
    int *oneRow;
    if (!ensureCapacity(collector)) return 0;
    oneRow = (int *)malloc((size_t)pathLen * sizeof(int));
    if (oneRow == NULL) return 0;

    memcpy(oneRow, path, (size_t)pathLen * sizeof(int));
    collector->rows[collector->count] = oneRow;
    collector->colSizes[collector->count] = pathLen;
    collector->count++;
    return 1;
}

static int dfsBuild(int *candidates, int candidatesSize, int startIndex, int remaining, int *path, int pathLen, struct ResultCollector *collector){
    int i;
    int value;
    if (remaining == 0) return pushCombination(collector, path, pathLen);
    for (i = startIndex; i < candidatesSize; i++){
        value = candidates[i];
        if (value > remaining) break;
        path[pathLen] = value;
        if (!dfsBuild(candidates, candidatesSize, i, remaining - value, path, pathLen + 1, collector)){
            return 0;
        }
    }
    return 1;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    struct ResultCollector collector;
    int *path;
    int ok;
    int i;

    if (returnSize != NULL) *returnSize = 0;
    if (returnColumnSizes != NULL) *returnColumnSizes = NULL;
    if (candidates == NULL || candidatesSize <= 0 || target < 0 || returnSize == NULL || returnColumnSizes == NULL){
        return NULL;
    }
    qsort(candidates, (size_t)candidatesSize, sizeof(int), compareIntAsc);

    collector.rows = NULL;
    collector.colSizes = NULL;
    collector.count = 0;
    collector.capacity = 16;

    collector.rows = (int **)malloc((size_t)collector.capacity * sizeof(int*));
    collector.colSizes = (int *)malloc((size_t)collector.capacity * sizeof(int));
    if (collector.rows == NULL || collector.colSizes == NULL){
        free(collector.rows);
        free(collector.colSizes);
        return NULL;
    }
    path = (int *)malloc((size_t)(target + 1) * sizeof(int));
    if (path == NULL){
        free(collector.rows);
        free(collector.colSizes);
        return NULL;
    }

    ok = dfsBuild(candidates, candidatesSize, 0, target, path, 0, &collector);
    free(path);
    if (!ok){
        for (i = 0; i < collector.count; i++){
            free(collector.rows[i]);
        }
        free(collector.rows);
        free(collector.colSizes);
        return NULL;
    }
    if (collector.count == 0){
        free(collector.rows);
        free(collector.colSizes);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    collector.rows = (int **)realloc(collector.rows, (size_t)collector.count * sizeof(int *));
    collector.colSizes = (int *)realloc(collector.colSizes, (size_t)collector.count * sizeof(int));
    *returnSize = collector.count;
    *returnColumnSizes = collector.colSizes;
    return collector.rows;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
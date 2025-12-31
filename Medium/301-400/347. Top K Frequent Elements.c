// 347. Top K Frequent Elements
//
// Given an integer array nums and an integer k, return the k most frequent 
// elements. You may return the answer in any order.
// 
// 
// Example 1:
// 
// Input: nums = [1,1,1,2,2,3], k = 2
// 
// Output: [1,2]
// 
// 
// Example 2:
// 
// Input: nums = [1], k = 1
// 
// Output: [1]
// 
// 
// Example 3:
// 
// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
// 
// Output: [1,2]
// 
// 
// Constraints:
// 
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
//  
// 
// Follow up: Your algorithm's time complexity must be better than O(n log n), 
// where n is the array's size.

#include <stdlib.h>     // malloc, free
#include <stddef.h>     // size_t
#include <string.h>     // memset

struct IntList {
    int *data;
    int size;
    int cap;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int listPush(struct IntList *lst, int x){
    int newCap;
    int *p;
    if (lst->size < lst->cap){
        lst->data[lst->size] = x;
        lst->size++;
        return 1;
    }
    newCap = (lst->cap == 0) ? 4 : (lst->cap * 2);
    p = (int *)realloc(lst->data, (size_t)newCap * sizeof(int));
    if (p == NULL) return 0;
    lst->data = p;
    lst->cap = newCap;
    lst->data[lst->size] = x;
    lst->size++;
    return 1;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    enum { OFFSET = 10000, RANGE = 20001 };
    int freq[RANGE];
    char present[RANGE];
    struct IntList *buckets;
    int *answer;
    int i;
    int idx;
    int maxFreq;
    int value;
    int f;
    int outCount;
    if (returnSize != NULL) *returnSize = 0;
    if (nums == NULL || numsSize <= 0 || k <= 0 || returnSize == NULL) return NULL;
    memset(freq, 0, sizeof(freq));
    memset(present, 0, sizeof(present));
    for (i = 0; i < numsSize; i++){
        idx = nums[i] + OFFSET;
        freq[idx]++;
        present[idx] = 1;
    }
    buckets = (struct IntList *)malloc((size_t)(numsSize + 1) * sizeof(struct IntList)); 
    if (buckets == NULL) return NULL;

        for (i = 0; i <= numsSize; i++) {
        buckets[i].data = NULL;
        buckets[i].size = 0;
        buckets[i].cap = 0;
    }

    maxFreq = 0;
    for (idx = 0; idx < RANGE; idx++) {
        if (!present[idx]) continue;
        f = freq[idx];
        value = idx - OFFSET;
        if (!listPush(&buckets[f], value)) {
            for (i = 0; i <= numsSize; i++) free(buckets[i].data);
            free(buckets);
            return NULL;
        }
        if (f > maxFreq) maxFreq = f;
    }

    answer = (int *)malloc((size_t)k * sizeof(int));
    if (answer == NULL) {
        for (i = 0; i <= numsSize; i++) free(buckets[i].data);
        free(buckets);
        return NULL;
    }

    outCount = 0;
    for (f = maxFreq; f >= 1 && outCount < k; f--) {
        for (i = 0; i < buckets[f].size && outCount < k; i++) {
            answer[outCount] = buckets[f].data[i];
            outCount++;
        }
    }

    for (i = 0; i <= numsSize; i++) free(buckets[i].data);
    free(buckets);

    *returnSize = outCount;
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
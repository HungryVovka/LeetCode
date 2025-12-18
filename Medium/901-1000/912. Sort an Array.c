// 912. Sort an Array
//
// Given an array of integers nums, sort the array in ascending order and return it.
// 
// You must solve the problem without using any built-in functions in O(nlog(n)) 
// time complexity and with the smallest space complexity possible.
// 
// 
// Example 1:
// 
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not 
// changed (for example, 2 and 3), while the positions of other numbers are changed 
// (for example, 1 and 5).
// 
// Example 2:
// 
// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessarily unique.
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 5 * 10^4
// -5 * 10^4 <= nums[i] <= 5 * 10^4

#include <stdlib.h>     // malloc, free
#include <stddef.h>     // size_t

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static void swapInt(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

static void siftDown(int *arr, int heapSize, int rootIndex){
    int parent;
    int leftChild, rightChild;
    int largest;
    parent = rootIndex;
    while (1){
        leftChild = 2 * parent + 1;
        if (leftChild >= heapSize) break;
        rightChild = leftChild + 1;
        largest = parent;
        if (arr[leftChild] > arr[largest]) largest = leftChild;
        if (rightChild < heapSize && arr[rightChild] > arr[largest]){
            largest = rightChild;
        }
        if (largest == parent) break;
        swapInt(&arr[parent], &arr[largest]);
        parent = largest;
    }
}

static void heapSort(int *arr, int n){
    int i;
    if (arr == NULL || n <= 1) return;
    i = (n / 2) - 1;
    while (i >= 0){
        siftDown(arr, n, i);
        i--;
    }
    i = n - 1;
    while (i > 0){
        swapInt(&arr[0], &arr[i]);
        siftDown(arr, i, 0);
        i--;
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    int *out;
    int i;
    if (returnSize != NULL) *returnSize = 0;
    if (nums == NULL || numsSize <= 0 || returnSize == NULL){
        return NULL;
    }
    out = (int *)malloc((size_t)numsSize * sizeof(int));
    if (out == NULL) return NULL;
    for (i = 0; i < numsSize; i++) out[i] = nums[i];
    heapSort(out, numsSize);
    *returnSize = numsSize;
    return out;
}

// or

#include <stdlib.h>     // malloc, free
#include <stddef.h>     // size_t

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static void radixSortSignedInt32(int *arr, int n){
    int *temp;
    int count[256];
    int prefix[256];
    int pass;
    int i;
    int shift;
    unsigned int key;
    int byteValue;
    int running;
    int pos;
    int *sourceArray;
    int *targetArray;
    int *swapArray;
    if (arr == NULL || n <= 1) return;
    temp = (int *)malloc((size_t)n * sizeof(int));
    if (temp == NULL) return;
    sourceArray = arr;
    targetArray = temp;
    for (pass = 0; pass < 4; pass++){
        shift = pass * 8;
        for (i = 0; i < 256; i++) count[i] = 0;
        for (i = 0; i < n; i++){
            key = ((unsigned int)sourceArray[i]) ^ 0x80000000u;
            byteValue = (int)((key >> shift) & 255u);
            count[byteValue]++;
        }
        running = 0;
        for (i = 0; i < 256; i++){
            prefix[i] = running;
            running += count[i];
        }
        for (i = 0; i < n; i++){
            key = ((unsigned int)sourceArray[i]) ^ 0x80000000u;
            byteValue = (int)((key >> shift) & 255u);
            pos = prefix[byteValue];
            targetArray[pos] = sourceArray[i];
            prefix[byteValue] = pos + 1;
        }
        swapArray = sourceArray;
        sourceArray = targetArray;
        targetArray = swapArray;
    }
    free(temp);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    int *out;
    int i;
    if (returnSize != NULL) *returnSize = 0;
    if (nums == NULL || numsSize <= 0 || returnSize == NULL){
        return NULL;
    }
    out = (int *)malloc((size_t)numsSize * sizeof(int));
    if (out == NULL) return NULL;
    for (i = 0; i < numsSize; i++) out[i] = nums[i];
    radixSortSignedInt32(out, numsSize);
    *returnSize = numsSize;
    return out;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
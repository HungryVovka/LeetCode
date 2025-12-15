// 15. 3Sum
//
// Given an integer array nums, return all the triplets 
// [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
// and nums[i] + nums[j] + nums[k] == 0.
// 
// Notice that the solution set must not contain duplicate triplets.
//  
// 
// Example 1:
// 
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:
// 
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:
// 
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
//  
// 
// Constraints:
// 
// 3 <= nums.length <= 3000
// -10^5 <= nums[i] <= 10^5

#include <stdlib.h>     // qsort, malloc, realloc, free
#include <stddef.h>     // sie_t

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static int compareIntAsc(const void *a, const void *b){
    int leftValue, rightValue;
    leftValue = *(const int *)a;
    rightValue = *(const int *)b;
    if (leftValue < rightValue) return -1;
    if (leftValue > rightValue) return 1;
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **triplets;
    int *columnSizes;
    int tripletsCapacity;
    int tripletsCount;
    int firstIndex;
    int leftIndex;
    int rightIndex;
    int firstValue;
    int sumValue;
    int *oneTriplet;

    if (returnSize != NULL) *returnSize = 0;
    if (returnColumnSizes != NULL) *returnColumnSizes = NULL;

    if (nums == NULL || numsSize < 3 || returnSize == NULL || returnColumnSizes == NULL){
        return NULL;
    }

    qsort(nums, (size_t)numsSize, sizeof(int), compareIntAsc);
    tripletsCapacity = 16;
    tripletsCount = 0;

    triplets = (int**)malloc((size_t)tripletsCapacity * sizeof(int*));
    columnSizes = (int*)malloc((size_t)tripletsCapacity * sizeof(int));

    if (triplets == NULL || columnSizes == NULL){
        free(triplets);
        free(columnSizes);
        return NULL;
    }

    for (firstIndex = 0; firstIndex < numsSize - 2; firstIndex++){
        firstValue = nums[firstIndex];
        if (firstIndex > 0 && firstValue == nums[firstIndex - 1]) continue;
        if (firstValue > 0) break;
        leftIndex = firstIndex + 1;
        rightIndex = numsSize - 1;
        while (leftIndex < rightIndex){
            sumValue = firstValue + nums[leftIndex] + nums[rightIndex];
            if (sumValue < 0){
                leftIndex++;
            } else if (sumValue > 0){
                rightIndex--;
            } else {
                oneTriplet = (int*)malloc(3 * sizeof(int));
                if (oneTriplet == NULL){
                    int i;
                    for (i = 0; i < tripletsCount; i++){
                        free(triplets[i]);
                    }
                    free(triplets);
                    free(columnSizes);
                    return NULL;
                }
                oneTriplet[0] = firstValue;
                oneTriplet[1] = nums[leftIndex];
                oneTriplet[2] = nums[rightIndex];

                if (tripletsCount == tripletsCapacity){
                    int newCapacity;
                    int **newTriplets;
                    int *newColumnSizes;

                    newCapacity = tripletsCapacity * 2;
                    newTriplets = (int **)realloc(triplets, (size_t)newCapacity * sizeof(int *));
                    newColumnSizes = (int *)realloc(columnSizes, (size_t)newCapacity * sizeof(int));

                    if (newTriplets == NULL || newColumnSizes == NULL){
                        int i;
                        free(oneTriplet);
                        if (newTriplets != NULL) triplets = newTriplets;
                        if (newColumnSizes != NULL) columnSizes = newColumnSizes;
                        for (i = 0; i < tripletsCount; i++) free(triplets[i]);
                        free(triplets);
                        free(columnSizes);
                        return NULL;
                    }
                    triplets = newTriplets;
                    columnSizes = newColumnSizes;
                    tripletsCapacity = newCapacity;
                }
                triplets[tripletsCount] = oneTriplet;
                columnSizes[tripletsCount] = 3;
                tripletsCount++;
                leftIndex++;
                rightIndex--;
                while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1]){
                    leftIndex++;
                }
                while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1]){
                    rightIndex--;
                }
            }
        }
    }
    *returnSize = tripletsCount;
    *returnColumnSizes = columnSizes;
    return triplets;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
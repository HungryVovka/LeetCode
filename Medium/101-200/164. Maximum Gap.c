// 164. Maximum Gap
// 
// Given an integer array nums, return the maximum difference between 
// two successive elements in its sorted form. If the array contains less 
// than two elements, return 0.
// 
// You must write an algorithm that runs in linear time and uses linear extra space.
// 
//  
// 
// Example 1:
// 
// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], 
// either (3,6) or (6,9) has the maximum difference 3.
// 
// Example 2:
// 
// Input: nums = [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^9

#include <stdlib.h>         // malloc, free
#include <stddef.h>         // size_t
#include <limits.h>         // INT_MAX, INT_MIN

struct Bucket {
    int used;
    int minValue;
    int maxValue;
};

static int ceilDivInt(int a, int b){
    return (a + b - 1) / b;
}

int maximumGap(int* nums, int numsSize){
    int i;
    int minVal;
    int maxVal;
    int range;
    int bucketSize;
    int bucketCount;

    struct Bucket *buckets;

    int index;
    int value;
    int previousMax;
    int maxGap;

    if (nums == NULL || numsSize < 2) return 0;

    minVal = INT_MAX;
    maxVal = INT_MIN;

    for (i = 0; i < numsSize; i++){
        value = nums[i];
        if (value < minVal) minVal = value;
        if (value > maxVal) maxVal = value;
    }

    if (minVal == maxVal) return 0;

    range = maxVal - minVal;
    bucketSize = ceilDivInt(range, numsSize - 1);
    if (bucketSize < 1) bucketSize = 1;

    bucketCount = (range / bucketSize) + 1;
    buckets = (struct Bucket *)malloc((size_t)bucketCount * sizeof(struct Bucket));
    if (buckets == NULL) return 0;

    for (i = 0; i < bucketCount; i++){
        buckets[i].used = 0;
        buckets[i].minValue = INT_MAX;
        buckets[i].maxValue = INT_MIN;
    }

    for (i = 0; i < numsSize; i++){
        value = nums[i];
        index = (value - minVal) / bucketSize;
        if (!buckets[index].used){
            buckets[index].used = 1;
            buckets[index].minValue = value;
            buckets[index].maxValue = value;
        } else {
            if (value < buckets[index].minValue) buckets[index].minValue = value;
            if (value > buckets[index].maxValue) buckets[index].maxValue = value;
        }
    }
    maxGap = 0;
    previousMax = 0;
    for (i = 0; i < bucketCount; i++){
        if (buckets[i].used){
            previousMax = buckets[i].maxValue;
            break;
        }
    }
    for (i = i + 1; i < bucketCount; i++){
        if (!buckets[i].used) continue;
        if (buckets[i].minValue - previousMax > maxGap){
            maxGap = buckets[i].minValue - previousMax;
        }
        previousMax = buckets[i].maxValue;
    }
    free(buckets);
    return maxGap;
}

// or

#include <stdlib.h>         // malloc, free
#include <stddef.h>         // size_t

void radixSortLSD_u32(int *array, int n){
    int *temp;
    int count[256];
    int prefix[256];
    int pass;
    int i;
    int byteValue;
    int shift;
    int running;
    int value;
    int pos;
    int *src;
    int *dst;
    int *swapPtr;

    if (array == NULL || n <= 1) return;
    temp = (int *)malloc((size_t)n * sizeof(int));
    if (temp == NULL) return;
    src = array;
    dst = temp;

    for (pass = 0; pass < 4; pass++){
        shift = pass * 8;
        for (i = 0; i < 256; i++) count[i] = 0;
        for (i = 0; i < n; i++){
            value = src[i];
            byteValue = (value >> shift) & 255;
            count[byteValue]++;
        }
        running = 0;
        for (i = 0; i < 256; i++){
            prefix[i] = running;
            running += count[i];
        }
        for (i = 0; i < n; i++){
            value = src[i];
            byteValue = (value >> shift) & 255;
            pos = prefix[byteValue];
            dst[pos] = value;
            prefix[byteValue] = pos + 1;
        }
        swapPtr = src;
        src = dst;
        dst = swapPtr;
    }
    free(temp);
}

int maximumGap(int *nums, int numsSize){
    int maxGap;
    int i;
    int diff;
    if (nums == NULL || numsSize < 2) return 0;
    radixSortLSD_u32(nums, numsSize);
    maxGap = 0;
    for (i = 1; i < numsSize; i++){
        diff = nums[i] - nums[i - 1];
        if (diff > maxGap) maxGap = diff;
    }
    return maxGap;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
// 220. Contains Duplicate III
//
// You are given an integer array nums and two integers indexDiff and valueDiff.
// 
// Find a pair of indices (i, j) such that:
// 
// i != j,
// abs(i - j) <= indexDiff.
// abs(nums[i] - nums[j]) <= valueDiff, and
// Return true if such pair exists or false otherwise.
// 
// 
// Example 1:
// Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
// Output: true
// Explanation: We can choose (i, j) = (0, 3).
// We satisfy the three conditions:
// i != j --> 0 != 3
// abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
// abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
// 
// Example 2:
// Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
// Output: false
// Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three // conditions, so we return false.
//  
// 
// Constraints:
// 
// 2 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9
// 1 <= indexDiff <= nums.length
// 0 <= valueDiff <= 10^9

#include <stdlib.h>     // malloc, free
#include <stddef.h>     // size_t
#include <limits.h>     // LLONG_MIN
#include <stdbool.h>    // bool, true, false  (used: bool)

struct BucketEntry {
    long long key;      // bucketId
    long long value;    // stored number
    char used;          // 0 empty, 1 occupied
};

static long long llabs_ll(long long x){
    return (x < 0) ? -x : x;
}

// floor(a / b) for b > 0 
static long long floorDivLL(long long a, long long b){
    long long q;
    long long r;
    q = a / b;
    r = a % b;
    if (r != 0 && ((a < 0) != (b < 0))) q--;
    return q;
}

static size_t hashKey(long long key){
    // simple mix 
    unsigned long long x;
    x = (unsigned long long)key;
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    return (size_t)x;
}

static int tableFindIndex(struct BucketEntry *table, int tableSize, long long key, int *outIndex){
    size_t h;
    int idx;
    int step;

    h = hashKey(key);
    idx = (int)(h % (size_t)tableSize);
    step = 0;

    while (step < tableSize){
        if (!table[idx].used){
            *outIndex = idx;
            return 0; // not found, idx is empty slot 
        }
        if (table[idx].key == key){
            *outIndex = idx;
            return 1; // found
        }
        idx++;
        if (idx == tableSize) idx = 0;
        step++;
    }

    *outIndex = -1;
    return 0;
}

static int tableInsert(struct BucketEntry *table, int tableSize, long long key, long long value){
    int idx;
    int found;

    found = tableFindIndex(table, tableSize, key, &idx);
    if (idx < 0) return 0;

    table[idx].used = 1;
    table[idx].key = key;
    table[idx].value = value;
    return 1;
}

// Tombstone-aware find/insert/erase 
static int tableFindIndexTS(struct BucketEntry *table, int tableSize, long long key, int *outIndex, int *outFirstTomb){
    size_t h;
    int idx;
    int step;
    int firstTomb;

    h = hashKey(key);
    idx = (int)(h % (size_t)tableSize);
    step = 0;
    firstTomb = -1;

    while (step < tableSize){
        if (!table[idx].used){
            *outIndex = idx;
            *outFirstTomb = firstTomb;
            return 0;
        }
        if (table[idx].key == key){
            *outIndex = idx;
            *outFirstTomb = firstTomb;
            return 1;
        }
        if (table[idx].key == LLONG_MIN && firstTomb < 0){
            firstTomb = idx;
        }
        idx++;
        if (idx == tableSize) idx = 0;
        step++;
    }

    *outIndex = -1;
    *outFirstTomb = firstTomb;
    return 0;
}

static int tableInsertTS(struct BucketEntry *table, int tableSize, long long key, long long value){
    int idx;
    int firstTomb;
    int found;

    found = tableFindIndexTS(table, tableSize, key, &idx, &firstTomb);
    if (found){
        table[idx].value = value;
        return 1;
    }
    if (idx < 0 && firstTomb < 0) return 0;

    if (firstTomb >= 0) idx = firstTomb;

    table[idx].used = 1;
    table[idx].key = key;
    table[idx].value = value;
    return 1;
}

static int tableGetTS(struct BucketEntry *table, int tableSize, long long key, long long *outValue){
    int idx;
    int firstTomb;
    int found;

    found = tableFindIndexTS(table, tableSize, key, &idx, &firstTomb);
    if (!found) return 0;
    *outValue = table[idx].value;
    return 1;
}

static void tableEraseTS(struct BucketEntry *table, int tableSize, long long key){
    int idx;
    int firstTomb;
    int found;


    found = tableFindIndexTS(table, tableSize, key, &idx, &firstTomb);
    if (!found) return;

    // tombstone 
    table[idx].key = LLONG_MIN;
    table[idx].value = 0;
    table[idx].used = 1;
}

// Return true if exists i!=j with |i-j|<=indexDiff and |nums[i]-nums[j]|<=valueDiff.

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff){
    long long w;
    int tableSize;
    struct BucketEntry *table;
    int i;

    if (nums == NULL || numsSize < 2) return false;
    if (indexDiff <= 0) return false;
    if (valueDiff < 0) return false;

    w = (long long)valueDiff + 1LL;

    tableSize = (indexDiff + 1) * 4 + 7;
    table = (struct BucketEntry *)malloc((size_t)tableSize * sizeof(struct BucketEntry));
    if (table == NULL) return false;

    for (i = 0; i < tableSize; i++){
        table[i].used = 0;
        table[i].key = 0;
        table[i].value = 0;
    }

    for (i = 0; i < numsSize; i++){
        long long x;
        long long id;
        long long neighborValue;
        int outIndex;
        int outFirstTomb;

        // 1) Maintain window BEFORE checking current element
        if (i > indexDiff){
            long long oldX;
            long long oldId;
            oldX = (long long)nums[i - indexDiff - 1];
            oldId = floorDivLL(oldX, w);
            tableEraseTS(table, tableSize, oldId);
        }

        x = (long long)nums[i];
        id = floorDivLL(x, w);

        // 2) Check same / neighbor buckets 
        if (tableFindIndexTS(table, tableSize, id, &outIndex, &outFirstTomb)){
            free(table);
            return true;
        }

        if (tableGetTS(table, tableSize, id - 1, &neighborValue)){
            if (llabs_ll(x - neighborValue) <= (long long)valueDiff){
                free(table);
                return true;
            }
        }

        if (tableGetTS(table, tableSize, id + 1, &neighborValue)){
            if (llabs_ll(x - neighborValue) <= (long long)valueDiff){
                free(table);
                return true;
            }
        }

        // 3) Insert current element 
        if (!tableInsertTS(table, tableSize, id, x)){
            free(table);
            return false;
        }
    }

    free(table);
    return false;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
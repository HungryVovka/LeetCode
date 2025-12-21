// 49. Group Anagrams
// 
// Given an array of strings strs, group the anagrams together. You can return the answer in 
// any order.
// 
// An Anagram is a word or phrase formed by rearranging the letters of a different word or 
// phrase, typically using all the original letters exactly once.
// 
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 
// Example 2:
// Input: strs = [""]
// Output: [[""]]
// 
// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]
// 
// Constraints:
// 
// 1 <= strs.length <= 10^4
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

#include <stdlib.h>     // malloc, free
#include <string.h>     // memcpy

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct {
    int frequency[26];
    char **words;
    int size;
} AnagramGroup;

static int same_frequency(const int *a, const int *b){
    int i;
    for (i = 0; i < 26; i++){
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    AnagramGroup *groups;
    int groupCount;
    int i, g;
    int groupIndex;
    int letter_freq[26];
    char *p;
    char ***answer;
    groups = (AnagramGroup *)malloc((size_t)strsSize * sizeof(AnagramGroup));
    groupCount = 0;
    for (i = 0; i < strsSize; i++){
        for (g = 0; g < 26; g++) letter_freq[g] = 0;
        p = strs[i];
        while (*p != '\0'){
            letter_freq[*p - 'a']++;
            p++;
        }
        groupIndex = -1;
        for (g = 0; g < groupCount; g++){
            if (same_frequency(groups[g].frequency, letter_freq)){
                groupIndex = g;
                break;
            }
        }
        if (groupIndex == -1){
            groupIndex = groupCount;
            groupCount++;
            memcpy(groups[groupIndex].frequency, letter_freq, sizeof(letter_freq));
            groups[groupIndex].words = (char **)malloc((size_t)strsSize * sizeof(char *));
            groups[groupIndex].size = 0;
        }
        groups[groupIndex].words[groups[groupIndex].size] = strs[i];
        groups[groupIndex].size++;
    }
    answer = (char ***)malloc((size_t)groupCount * sizeof(char **));
    *returnColumnSizes = (int *)malloc((size_t)groupCount * sizeof(int));
    for (i = 0; i < groupCount; i++){
        answer[i] = groups[i].words;
        (*returnColumnSizes)[i] = groups[i].size;
    }
    *returnSize = groupCount;
    return answer;
}

// or

#include <stdlib.h>   // malloc, free, qsort
#include <string.h>   // strlen, memcpy, strcmp

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct {
    char *key;   // sorted copy
    char *word;  // original pointer
} Item;

static int cmp_char(const void *a, const void *b) {
    char ca = *(const char*)a;
    char cb = *(const char*)b;
    return (ca > cb) - (ca < cb);
}

static int cmp_item_by_key(const void *a, const void *b) {
    const Item *ia = (const Item*)a;
    const Item *ib = (const Item*)b;
    return strcmp(ia->key, ib->key);
}

// strdup не стандарт C, делаем свою 
static char *dup_string(const char *s) {
    size_t n = strlen(s);
    char *copy = (char*)malloc(n + 1);
    if (!copy) return NULL;
    memcpy(copy, s, n + 1);
    return copy;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Item *items;
    int i;

    int groupCount;
    int start;
    int groupIndex;

    char ***answer;

    if (strsSize <= 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    items = (Item*)malloc((size_t)strsSize * sizeof(Item));
    if (!items) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // build (key, word)
    for (i = 0; i < strsSize; i++) {
        char *key = dup_string(strs[i]);
        size_t len;

        if (!key) {
            // best-effort cleanup
            int j;
            for (j = 0; j < i; j++) free(items[j].key);
            free(items);
            *returnSize = 0;
            *returnColumnSizes = NULL;
            return NULL;
        }

        len = strlen(key);
        qsort(key, len, sizeof(char), cmp_char);  // sort letters 
        items[i].key = key;
        items[i].word = strs[i];
    }

    // sort items by key
    qsort(items, (size_t)strsSize, sizeof(Item), cmp_item_by_key);

    /* count groups */
    groupCount = 0;
    i = 0;
    while (i < strsSize) {
        int j = i + 1;
        while (j < strsSize && strcmp(items[i].key, items[j].key) == 0) j++;
        groupCount++;
        i = j;
    }

    answer = (char***)malloc((size_t)groupCount * sizeof(char**));
    *returnColumnSizes = (int*)malloc((size_t)groupCount * sizeof(int));
    if (!answer || !*returnColumnSizes) {
        for (i = 0; i < strsSize; i++) free(items[i].key);
        free(items);
        free(answer);
        free(*returnColumnSizes);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // build groups
    groupIndex = 0;
    start = 0;
    while (start < strsSize) {
        int end = start + 1;
        int size;
        char **group;

        while (end < strsSize && strcmp(items[start].key, items[end].key) == 0) end++;
        size = end - start;

        group = (char**)malloc((size_t)size * sizeof(char*));
        if (!group) {
            // cleanup (caller expects allocated output, so we must free)
            int k;
            for (k = 0; k < groupIndex; k++) free(answer[k]);
            free(answer);
            free(*returnColumnSizes);
            for (i = 0; i < strsSize; i++) free(items[i].key);
            free(items);
            *returnSize = 0;
            *returnColumnSizes = NULL;
            return NULL;
        }

        for (i = 0; i < size; i++) {
            group[i] = items[start + i].word;
        }

        answer[groupIndex] = group;
        (*returnColumnSizes)[groupIndex] = size;
        groupIndex++;

        start = end;
    }

    *returnSize = groupCount;

    // internal cleanup: keys + items
    for (i = 0; i < strsSize; i++) free(items[i].key);
    free(items);

    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
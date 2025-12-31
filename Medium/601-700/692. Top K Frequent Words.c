// 692. Top K Frequent Words
// 
// Given an array of strings words and an integer k, return the k most frequent strings.
// 
// Return the answer sorted by the frequency from highest to lowest. Sort the words 
// with the same frequency by their lexicographical order.
// 
// 
// Example 1:
// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.
// 
// Example 2:
// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, 
// with the number of occurrence being 4, 3, 2 and 1 respectively.
//  
// 
// Constraints:
// 
// 1 <= words.length <= 500
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// k is in the range [1, The number of unique words[i]]
//  
// 
// Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

#include <stdlib.h>     // qsort, malloc, free
#include <stddef.h>     // size_t
#include <string.h>     // strcmp, strlen, memcpy

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int compareCStrAsc(const void *a, const void *b){
    const char *sa;
    const char *sb;
    sa = *(const char * const *)a;
    sb = *(const char * const *)b;
    return strcmp(sa, sb);
}

static char *dupString(const char *s){
    size_t len;
    char *out;
    len = strlen(s);
    out = (char *)malloc(len + 1);
    if (out == NULL) return NULL;
    memcpy(out, s, len + 1);
    return out;
}

struct WordCount {
    const char *word;
    int count;
};

struct Bucket {
    const char **items;
    int size;
    int capacity;
};

static int bucketPush(struct Bucket *bucket, const char *word){
    int newCap;
    const char **newItems;
    if (bucket->size < bucket->capacity){
        bucket->items[bucket->size] = word;
        bucket->size++;
        return 1;
    }
    newCap = (bucket->capacity == 0) ? 4 : bucket->capacity * 2;
    newItems = (const char **)realloc(bucket->items, (size_t)newCap * sizeof(const char *)); 
    if (newItems == NULL) return 0;
    bucket->items = newItems; 
    bucket->capacity = newCap; 
    bucket->items[bucket->size] = word; 
    bucket->size++; 
    return 1;
}

char** topKFrequent(char** words, int wordsSize, int k, int* returnSize)
{
    struct WordCount *unique;
    int uniqueCount;
    int i;
    int maxFreq;
    struct Bucket *buckets;
    int freq;
    char **answer;
    int answerCount;

    if (returnSize != NULL) *returnSize = 0;
    if (words == NULL || wordsSize <= 0 || k <= 0 || returnSize == NULL) return NULL;

    // 1) Sort words lexicographically
    qsort(words, (size_t)wordsSize, sizeof(char *), compareCStrAsc);

    // 2) Build (word, count) for unique words
    unique = (struct WordCount *)malloc((size_t)wordsSize * sizeof(struct WordCount));
    if (unique == NULL) return NULL;

    uniqueCount = 0;
    i = 0;
    maxFreq = 0;

    while (i < wordsSize) {
        int runCount;
        int j;

        runCount = 1;
        j = i + 1;
        while (j < wordsSize && strcmp(words[i], words[j]) == 0) {
            runCount++;
            j++;
        }

        unique[uniqueCount].word = words[i];
        unique[uniqueCount].count = runCount;
        uniqueCount++;

        if (runCount > maxFreq) maxFreq = runCount;

        i = j;
    }

    // 3) Buckets by frequency: buckets[f] holds words with count=f (already lex-sorted)
    buckets = (struct Bucket *)malloc((size_t)(maxFreq + 1) * sizeof(struct Bucket));
    if (buckets == NULL) {
        free(unique);
        return NULL;
    }

    for (freq = 0; freq <= maxFreq; freq++) {
        buckets[freq].items = NULL;
        buckets[freq].size = 0;
        buckets[freq].capacity = 0;
    }

    for (i = 0; i < uniqueCount; i++) {
        int c;
        c = unique[i].count;
        if (!bucketPush(&buckets[c], unique[i].word)) {
            // cleanup buckets
            for (freq = 0; freq <= maxFreq; freq++) {
                free(buckets[freq].items);
            }
            free(buckets);
            free(unique);
            return NULL;
        }
    }

    // 4) Build answer from highest freq down, respecting lex order inside buckets
    answer = (char **)malloc((size_t)k * sizeof(char *));
    if (answer == NULL) {
        for (freq = 0; freq <= maxFreq; freq++) free(buckets[freq].items);
        free(buckets);
        free(unique);
        return NULL;
    }
    answerCount = 0;
    for (freq = maxFreq; freq >= 1 && answerCount < k; freq--) {
        int b;
        for (b = 0; b < buckets[freq].size && answerCount < k; b++) {
            char *copy;
            copy = dupString(buckets[freq].items[b]);
            if (copy == NULL) {
                int t;
                for (t = 0; t < answerCount; t++) free(answer[t]);
                free(answer);
                for (freq = 0; freq <= maxFreq; freq++) free(buckets[freq].items);
                free(buckets);
                free(unique);
                return NULL;
            }
            answer[answerCount] = copy;
            answerCount++;
        }
    }
    *returnSize = answerCount;
    for (freq = 0; freq <= maxFreq; freq++) free(buckets[freq].items);
    free(buckets);
    free(unique);
    return answer;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
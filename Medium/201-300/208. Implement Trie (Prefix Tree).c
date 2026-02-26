// 208. Implement Trie (Prefix Tree)
//
// A trie (pronounced as "try") or prefix tree is a tree data structure used 
// to efficiently store and retrieve keys in a dataset of strings. There are 
// various applications of this data structure, such as autocomplete and spellchecker.
// 
// Implement the Trie class:
// 
// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in 
// the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously 
// inserted string word that has the prefix prefix, and false otherwise.
//  
// 
// Example 1:
// 
// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]
// 
// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
//  
// 
// Constraints:
// 
// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.

#include <stdlib.h>     // malloc, free
#include <stdbool.h>    // bool, true, false
#include <string.h>     // strlen

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool is_end_of_word;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

static TrieNode* createNode() {
    int i;
    TrieNode* new_node = (TrieNode*)malloc(sizeof(TrieNode));
    if (new_node == NULL) return NULL;
    for (i = 0; i < 26; i++){
        new_node->children[i] = NULL;
    }
    new_node->is_end_of_word = false;
    return new_node;
}

Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    if (trie == NULL) return NULL;
    trie->root = createNode();
    return trie;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* current_node;
    int i;
    int char_i;
    int word_l;
    if (obj == NULL || word == NULL) return;
    current_node = obj->root;
    word_l = strlen(word);
    for (i = 0; i < word_l; i++){
        char_i = word[i] - 'a';
        if (current_node->children[char_i] == NULL){
            current_node->children[char_i] = createNode();
        }
        current_node = current_node->children[char_i];
    }
    current_node->is_end_of_word = true;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* current_node;
    int i;
    int char_i;
    int word_l;
    if (obj == NULL || word == NULL) return false;
    current_node = obj->root;
    word_l = strlen(word);
    for (i = 0; i < word_l; i++){
        char_i = word[i] - 'a';
        if (current_node->children[char_i] == NULL) return false;
        current_node = current_node->children[char_i];
    }
    return current_node->is_end_of_word;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* current_node;
    int i;
    int char_i;
    int prefix_l;
    if (obj == NULL || prefix == NULL) return false;
    current_node = obj->root;
    prefix_l = strlen(prefix);
    for (i = 0; i < prefix_l; i++){
        char_i = prefix[i] - 'a';
        if (current_node->children[char_i] == NULL) return false;
        current_node = current_node->children[char_i];
    }
    return true;
}

static void freeNode(TrieNode* node){
    int i;
    if (node == NULL) return;
    for (i = 0; i < 26; i++){
        if (node->children[i] != NULL) freeNode(node->children[i]);
    }
    free(node);
}

void trieFree(Trie* obj) {
    if (obj == NULL) return;
    freeNode(obj->root);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
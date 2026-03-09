// 1488. Avoid Flood in The City
//
// Your country has 10^9 lakes. Initially, all the lakes are empty, but when it 
// rains over the nth lake, the nth lake becomes full of water. If it rains over a 
// lake that is full of water, there will be a flood. Your goal is to avoid floods in any lake.
// 
// Given an integer array rains where:
// 
// rains[i] > 0 means there will be rains over the rains[i] lake.
// rains[i] == 0 means there are no rains this day and you must choose one lake this day and dry it.
// 
// Return an array ans where:
// 
// ans.length == rains.length
// ans[i] == -1 if rains[i] > 0.
// ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
// If there are multiple valid answers return any of them. If it is impossible to avoid flood 
// return an empty array.
// 
// Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an 
// empty lake, nothing changes.
// 
//  
// 
// Example 1:
// 
// Input: rains = [1,2,3,4]
// Output: [-1,-1,-1,-1]
// Explanation: After the first day full lakes are [1]
// After the second day full lakes are [1,2]
// After the third day full lakes are [1,2,3]
// After the fourth day full lakes are [1,2,3,4]
// There's no day to dry any lake and there is no flood in any lake.
// 
// Example 2:
// 
// Input: rains = [1,2,0,0,2,1]
// Output: [-1,-1,2,1,-1,-1]
// Explanation: After the first day full lakes are [1]
// After the second day full lakes are [1,2]
// After the third day, we dry lake 2. Full lakes are [1]
// After the fourth day, we dry lake 1. There is no full lakes.
// After the fifth day, full lakes are [2].
// After the sixth day, full lakes are [1,2].
// It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another acceptable scenario.
// 
// Example 3:
// 
// Input: rains = [1,2,0,1,2]
// Output: []
// Explanation: After the second day, full lakes are  [1,2]. We have to dry one lake in the third day.
// After that, it will rain over lakes [1,2]. It's easy to prove that no matter which lake you 
// choose to dry in the 3rd day, the other one will flood.
//  
// 
// Constraints:
// 
// 1 <= rains.length <= 10^5
// 0 <= rains[i] <= 10^9

#include <stdlib.h>  // malloc, free
#include <string.h>  // memset

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define PLACEHOLDER_LAKE 1

typedef struct {
    int key;
    int value;
} MapItem;

typedef struct {
    MapItem *items;
    int capacity;
} HashMap;

int hash(int key, int cap){
    return (key * 2654435761u) % cap;
}

void initHashMap(HashMap *map, int capacity){
    int i;
    map->capacity = capacity * 2;
    map->items = (MapItem *)malloc(sizeof(MapItem) * map->capacity);
    for (i = 0; i < map->capacity; i++) map->items[i].key = -1;
}

void freeHashMap(HashMap *map){
    free(map->items);
}

int hashFind(HashMap *map, int key){
    int idx, i, cur;
    idx = hash(key, map->capacity);
    for (i = 0; i < map->capacity; i++){
        cur = (idx + i) % map->capacity;
        if (map->items[cur].key == -1) return -1;
        if (map->items[cur].key == key) return map->items[cur].value;
    }
    return -1;
}

void hashInsert(HashMap *map, int key, int value){
    int idx, i, cur;
    idx = hash(key, map->capacity);
    for (i = 0; i < map->capacity; i++){
        cur = (idx + i) % map->capacity;
        if (map->items[cur].key == -1 || map->items[cur].key == key){
            map->items[cur].key = key;
            map->items[cur].value = value;
            return;
        }
    }
}

// ===== AVL для сухих дней =====
typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

int height(AVLNode *n){
    if (!n) return 0;
    return n->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

AVLNode* createNode(int key){
    AVLNode *node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode* rightRotate(AVLNode *y){
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode *x){
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(AVLNode *n){
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

AVLNode* insertAVL(AVLNode* node, int key){
    if (!node) return createNode(key);

    if (key < node->key)
        node->left = insertAVL(node->left, key);
    else
        node->right = insertAVL(node->right, key);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLNode* minValueNode(AVLNode* node){
    AVLNode* current = node;
    while (current && current->left) current = current->left;
    return current;
}

AVLNode* deleteAVL(AVLNode* root, int key){
    if (!root) return root;
    if (key < root->key) root->left = deleteAVL(root->left, key);
    else if (key > root->key) root->right = deleteAVL(root->right, key);
    else {
        if (!root->left || !root->right){
            AVLNode *temp = root->left ? root->left : root->right;
            if (!temp){
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteAVL(root->right, temp->key);
        }
    }

    if (!root) return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

AVLNode* findGreater(AVLNode* root, int target){
    AVLNode* current = root;
    AVLNode* res = NULL;
    while (current){
        if (current->key > target){
            res = current;
            current = current->left;
        } else current = current->right;
    }
    return res;
}

void freeAVL(AVLNode* root){
    if (!root) return;
    freeAVL(root->left);
    freeAVL(root->right);
    free(root);
}

int* avoidFlood(int* rains, int n, int* returnSize){
    int *ans, i;
    AVLNode* dryRoot = NULL;
    *returnSize = n;
    ans = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) ans[i] = 0;

    HashMap map;
    initHashMap(&map, n);

    for (i = 0; i < n; i++){
        if (rains[i] == 0){
            dryRoot = insertAVL(dryRoot, i);
            ans[i] = PLACEHOLDER_LAKE;
        } else {
            int lake = rains[i];
            int last = hashFind(&map, lake);
            ans[i] = -1;
            if (last != -1){
                AVLNode* node = findGreater(dryRoot, last);
                if (!node){
                    free(ans);
                    freeAVL(dryRoot);
                    freeHashMap(&map);
                    *returnSize = 0;
                    return NULL;
                }
                ans[node->key] = lake;
                dryRoot = deleteAVL(dryRoot, node->key);
            }
            hashInsert(&map, lake, i);
        }
    }

    freeAVL(dryRoot);
    freeHashMap(&map);
    return ans;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
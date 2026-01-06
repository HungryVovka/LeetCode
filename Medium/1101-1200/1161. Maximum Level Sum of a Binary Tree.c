// 1161. Maximum Level Sum of a Binary Tree
//
// Given the root of a binary tree, the level of its root is 1, the level of its 
// children is 2, and so on.
// 
// Return the smallest level x such that the sum of all the values of nodes at 
// level x is maximal.
// 
// 
// Example 1:
//
//         (1)
//        /   \
//      (7)   (0)
//      / \
//    (7) (-8)
// 
// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
// 
// Example 2:
// 
// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2
//  
// 
// Constraints:
// 
// The number of nodes in the tree is in the range [1, 10^4].
// -10^5 <= Node.val <= 10^5

#include <stdlib.h>     // malloc, free
#include <limits.h>     // LLONG_MIN

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root){
    struct TreeNode **queue;
    int head;
    int tail;
    int capacity;
    int level;
    int bestLevel;
    long long bestSum;
    int i;
    int levelCount;
    long long levelSum;
    if (root == NULL) return 0;
    capacity = 10000 + 5;
    queue = (struct TreeNode **)malloc((size_t)capacity * sizeof(struct TreeNode *));
    if (queue == NULL) return 0;
    head = 0;
    tail = 0;
    queue[tail] = root;
    tail++;
    level = 0;
    bestLevel = 1;
    bestSum = LLONG_MIN;
    while (head < tail){
        level++;
        levelCount = tail - head;
        levelSum = 0;
        for (i = 0; i < levelCount; i++){
            struct TreeNode *node;
            node = queue[head];
            head++;
            levelSum += (long long)node->val;
            if (node->left != NULL){
                queue[tail] = node->left;
                tail++;
            }
            if (node->right != NULL){
                queue[tail] = node->right;
                tail++;
            }
        }
        if (levelSum > bestSum){
            bestSum = levelSum;
            bestLevel = level;
        }
    }
    free(queue);
    return bestLevel;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
// 1339. Maximum Product of Splitted Binary Tree
//
// Given the root of a binary tree, split the binary tree into two subtrees by removing 
// one edge such that the product of the sums of the subtrees is maximized.
// 
// Return the maximum product of the sums of the two subtrees. Since the answer may be 
// too large, return it modulo 10^9 + 7.
// 
// Note that you need to maximize the answer before taking the mod and not after taking it.
//
// Example 1:
// 
//         (1)                         (2)                 (1)
//        /   \                       /   \                   \
//      (2)   (3)        --->       (4)   (5)                 (3)
//      / \     \                                           /
//    (4) (5)   (6)                                       (6)
// 
//    sum = 11                                           sum = 10
// 
// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
// Their product is 110 (11*10)
// 
// Example 2:
// 
//         (1)                         (1)                 (4)
//          \                           \                 /   \
//          (2)           --->          (2)             (5)   (6)
//         /   \                         /
//       (3)   (4)                     (3)
//            /   \
//          (5)   (6)
// 
//        sum = 6                                     sum = 15
// 
// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.
// Their product is 90 (15*6)
//  
// Constraints:
// 
// The number of nodes in the tree is in the range [2, 5 * 10^4].
// 1 <= Node.val <= 10^4

#include <stdlib.h>     // malloc, free
#include <stddef.h>     // size_t
#include <limits.h>     // LLONG_MAX
#include <stdint.h>     // int64_t

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static long long dfsTotalSum(struct TreeNode *node){
    long long sum;
    if (node == NULL) return 0;
    sum = (long long)node->val;
    sum += dfsTotalSum(node->left);
    sum += dfsTotalSum(node->right);
    return sum;
}

static long long dfsSubtreeSums(struct TreeNode *node, long long totalSum, long long *bestProduct){
    long long leftSum;
    long long rightSum;
    long long subSum;
    long long product;
    if (node == NULL) return 0;
    leftSum = dfsSubtreeSums(node->left, totalSum, bestProduct);
    rightSum = dfsSubtreeSums(node->right, totalSum, bestProduct);
    subSum = (long long)node->val + leftSum + rightSum;
    product = subSum * (totalSum -subSum);
    if (product > *bestProduct) *bestProduct = product;
    return subSum;
}

int maxProduct(struct TreeNode* root){
    const int MOD = 1000000007;
    long long totalSum;
    long long bestProduct;
    long long answer;
    if (root == NULL) return 0;
    totalSum = dfsTotalSum(root);
    bestProduct = 0;
    dfsSubtreeSums(root, totalSum, &bestProduct);
    answer = bestProduct % (long long)MOD;
    return (int)answer;
}

// or

#include <stdlib.h>     // malloc, free
#include <stddef.h>     // size_t
#include <stdint.h>     // int64_t

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static long long collectSubSums(struct TreeNode *node, long long *arr, int *pos){
    long long leftSum;
    long long rightSum;
    long long subSum;

    if (node == NULL) return 0;

    leftSum = collectSubSums(node->left, arr, pos);
    rightSum = collectSubSums(node->right, arr, pos);

    subSum = (long long)node->val + leftSum + rightSum;
    arr[*pos] = subSum;
    *pos = *pos + 1;

    return subSum;
}

int maxProduct(struct TreeNode* root){
    const int MOD = 1000000007;
    long long *subSums;
    int count;
    long long totalSum;
    long long bestProduct;
    int i;
    long long s;
    long long product;

    if (root == NULL) return 0;

    /* Max nodes is 5*10^4 by constraints */
    subSums = (long long *)malloc((size_t)50000 * sizeof(long long));
    if (subSums == NULL) return 0;

    count = 0;
    totalSum = collectSubSums(root, subSums, &count);

    bestProduct = 0;
    for (i = 0; i < count; i++){
        s = subSums[i];
        product = s * (totalSum - s);
        if (product > bestProduct) bestProduct = product;
    }
    free(subSums);
    return (int)(bestProduct % (long long)MOD);
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
// 21. Merge Two Sorted Lists
// 
// You are given the heads of two sorted linked lists list1 and list2.
// 
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// 
// Return the head of the merged linked list.
// 
// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// 
// Example 2:
// Input: list1 = [], list2 = []
// Output: []
// 
// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]
// 
// Constraints:
// 
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

#include <stdlib.h>     // malloc, free

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* lista1, struct ListNode* lista2){
    struct ListNode nodo_fittizio;      // nodo fittizio per semplificare
    struct ListNode *corrente;          // puntatore al nodo corrente
    
    nodo_fittizio.val = 0;              // valore inutile (segnaposto)
    nodo_fittizio.next = NULL;
    corrente = &nodo_fittizio;          // inizialmente punta al fittizio

    while (lista1 != NULL && lista2 != NULL){
        if (lista1->val < lista2->val){
            corrente->next = lista1;    // collega lista1 al risultato
            lista1 = lista1->next;      // avanza lista1
        } else {
            corrente->next = lista2;    //collega lista2 al risultato
            lista2 = lista2->next;      //avanza lista2
        }
        corrente = corrente->next;      // avanza il puntatore corrente
    }

    if (lista1 != NULL){                // collega la lista rimanente (se esiste)
        corrente->next = lista1;
    } else if (lista2 != NULL){
        corrente->next = lista2;
    }
    
    return nodo_fittizio.next;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).
// Leet Code -> 160. Intersection of Two Linked Lists

// Given the heads of two singly linked-lists headA and headB,
// return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.

// For example, the following two linked lists
// begin to intersect at node c1:

// The test cases are generated such that there are no
// cycles anywhere in the entire linked structure.

// Note that the linked lists must retain their original
// structure after the function returns.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// TC -> O(max(2(N,M))
// SC -> O(1)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *d1 = headA;
        ListNode *d2 = headB;
        // create two pointers pointing at head of each list.

        while (d1 != d2)
        {
            d1 = d1 == NULL ? headB : d1->next;
            // if d1 is NULL, then point d1 to head of other linked list.

            d2 = d2 == NULL ? headA : d2->next;
            // if d2 is NULL, then point d2 to head of other linked list.

            // do a dry run to understand why both d1, d2 meet at same
            // node which is the point of intersection.
            // can return either d1 or d2, both will point to same node.
        }
        return d1;
    }
};
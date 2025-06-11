// Leet Code -> 206. Reverse Linked List

// Given the head of a singly linked list,
// reverse the list, and return the reversed list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//  TC -> O(N)
//  SC -> O(1)

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevptr = NULL;
        ListNode *currptr = head;
        ListNode *nextptr;
        while (currptr != NULL)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr; // this becomes the new head
    }
};
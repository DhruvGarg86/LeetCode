// Leet Code -> 21. Merge Two Sorted Lists

// You are given the heads of two sorted linked 
// lists list1 and list2.

// Merge the two lists into one sorted list. 
// The list should be made by splicing together 
// the nodes of the first two lists.

// Return the head of the merged linked list.



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

// TC -> O(n+m)
// n -> size of list1
// m -> size of list2
// SC -> O(1)

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Base case: if either list is empty, return the other list

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if (list1->val > list2->val)
            swap(list1, list2); // Making sure list 1 is always the smaller one
        ListNode *res = list1;  // store the result list

        // Merge the two lists
        while (list1 != NULL && list2 != NULL)
        {
            ListNode *tmp = NULL;
            while (list1 != NULL && list1->val <= list2->val)
            {
                tmp = list1;
                list1 = list1->next;
            }
            tmp->next = list2;
            swap(list1, list2);
        }
        return res;
    }
};
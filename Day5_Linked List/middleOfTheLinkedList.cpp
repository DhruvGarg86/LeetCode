// Leet Code -> 876. Middle of the Linked List

// Given the head of a singly linked list,
// return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

// TC -> O(N/2) ~ O(N)
// Sc -> O(1)

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
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        // The order of checking conditions is important.
        // If we check fast->next = NULL
        // we might miss the case where fast has already on NULL,
        // meaning the fast pointer has reached the end of the linked list,
        // and there is nothing to check in fast->next, because next of NULL doesn't exist.
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
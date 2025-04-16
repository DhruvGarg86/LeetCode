// Leet Code -> 19. Remove Nth Node From End of List

// Given the head of a linked list, 
// remove the nth node from the end of 
// the list and return its head.


// TC -> O(N)
// SC -> O(1)

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
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* fastp = head;
            ListNode* slowp = head;
            for(int i = 0; i < n; i++)
            {
                fastp = fastp -> next;
            }
            if(fastp == NULL)
            {
                return head;
            }
            while(fastp != NULL)
            {
                fastp = fastp -> next;
                slowp = slowp -> next;
            }
            ListNode* delnode = slowp -> next;
            slowp->next = slowp->next->next;
            delete delnode;
            return head;
        }
    
    };
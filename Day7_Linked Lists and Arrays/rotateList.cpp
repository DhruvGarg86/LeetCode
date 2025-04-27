// Leet Code -> 61. Rotate List

// Given the head of a linked list, rotate 
// the list to the right by k places.

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

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


// TC -> O(N) + O(N-(N % K)) -> O(N)
// SC -> O(1)
class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL || head->next == NULL || k == 0 )
                return head;
            ListNode* curr = head;
            int length = 1;
            while(curr->next != NULL){
                curr = curr -> next;
                ++length;
            }
            curr->next = head;
            k = k % length;
            k = length - k;
    
            while(k--)
                curr = curr->next;
    
            head = curr->next;
            curr->next = NULL;
    
            return head;
        }
    };
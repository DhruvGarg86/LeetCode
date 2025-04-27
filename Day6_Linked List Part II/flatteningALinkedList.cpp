// GFG -> Flattening a Linked List
// Problem Link -> https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Given a linked list containing n head nodes where 
// every node in the linked list contains two pointers:

// (i) next points to the next node in the list.
// (ii) bottom pointer to a sub-linked list where the 
// current node is the head.

// Each of the sub-linked lists nodes and the head nodes
// are sorted in ascending order based on their data.

// Your task is to flatten the linked list such that all 
// the nodes appear in a single level while maintaining 
// the sorted order.

// Note:
// 1. ↓ represents the bottom pointer 
// and -> represents the next pointer.

// 2. The flattened list will be printed using
//  the bottom pointer instead of the next pointer.

// TC -> O(N * M) (N = Number of lists ; M = Number of elements in each list)
// SC -> O(N) (N = Number of lists) (due to recursion stack)
class Solution {
    public:
      // Function which returns the  root of the flattened linked list.
      
      Node *mergeTwoLists(Node* list1, Node* list2 ){
          if(list1 == NULL)
              return list2;
          if(list2 == NULL)
              return list1;
              
          if(list1->data > list2 ->data){
              swap(list1, list2);
          }
          Node* dummy = new Node(0);
          Node* temp = dummy;
          
          while(list1 != NULL && list2 != NULL)
          {
              if(list1->data < list2->data){
                  temp->bottom = list1;
                  list1=list1->bottom;
              }   
              else{
                  temp->bottom=list2;
                  list2=list2->bottom;
              }
              temp = temp->bottom;
          }
          if(list1) temp->bottom = list1;
          else temp->bottom = list2;
          
          return dummy->bottom;
      }
      Node *flatten(Node *root) {
          // Your code here
          if(root == NULL || root->next == NULL){
              return root;
          }
          
          root->next= flatten(root->next);
          
          root = mergeTwoLists(root, root->next);
          
          return root;
      }
  };
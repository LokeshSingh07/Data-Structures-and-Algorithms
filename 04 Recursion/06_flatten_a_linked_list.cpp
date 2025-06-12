// Flattening a Linked List


/* Node structure  used in the program
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeTwoSortedLists(Node* list1, Node* list2){
        if(!list1) return list2;
        if(!list2) return list1;
        
        Node* result;
        if(list1->data < list2->data){
            result = list1;
            result->bottom = mergeTwoSortedLists(list1->bottom, list2);
        }
        else{
            result = list2;
            result->bottom = mergeTwoSortedLists(list1, list2->bottom);
        }
        
        return result;
    }
  
    Node* flatten(Node* root) {
        if(!root) return NULL;
        
        Node* head = flatten(root->next);
        return mergeTwoSortedLists(root, head);
    }
};
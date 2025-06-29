// Remove loop in Linked List


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    void removeLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        // detect loop
        while(fast){
            fast = fast->next;
            if(fast){
                slow = slow->next;
                fast = fast->next;
            }
            
            if(slow == fast){
                slow = head;
                
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                
                Node* startingNode = slow;
                while(slow->next != startingNode){
                    slow = slow->next;
                }
                slow->next = NULL;
                return;
            }
                
        }
        
    }
};
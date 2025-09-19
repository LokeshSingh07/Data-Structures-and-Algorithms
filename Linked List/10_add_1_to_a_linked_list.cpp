// Add 1 to a Linked List Number

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        if(!head || !head->next) return head;
        
        Node* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
  
    Node* addOne(Node* head) {
        head = reverse(head);
        
        Node* curr = head;
        Node* prev = NULL;
        int carry = 1;
        
        while(carry && curr){
            int sum = carry + curr->data;
            curr->data = sum % 10;
            prev = curr;
            curr = curr->next;
            carry = sum / 10;
        }
        
        if(carry){
            prev->next = new Node(carry);
        }
        
        head = reverse(head);
    
        return head;    
    }
};
// Delete N nodes after M nodes of a linked list

/*
struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        int keep = m;
        int skip = n;
        Node* temp = head;
        Node* forward = NULL;
        
        while(temp){
            if(keep > 1){
                keep--;
                temp = temp->next;
            }
            else{
                forward = temp->next;
                while(forward && skip){
                    skip--;
                    forward = forward->next;
                }
                temp->next = forward;
                temp = temp->next;
                
                keep = m;
                skip = n;
            }
        }
        
        return head;
    }
};
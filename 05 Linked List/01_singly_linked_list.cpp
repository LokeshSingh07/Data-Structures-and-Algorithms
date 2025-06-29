// singly linked list implementation
// insertion    -> atHead, atTail, atMiddle
// deletion
// searching
// length
// printing


#include<iostream>
using namespace std;

class Node{
  public:
    int val;
    Node* next;

    Node(){
        this->val = 0;
        this->next = NULL;
    }

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};



// insertion
void insertAtHead(Node* &head, Node* &tail, int val){
    if(!head){
        Node* newNode = new Node(val);
        head = tail = newNode;
    }
    else{
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(!head){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}


// length
// 1->2->3->4->5
int findLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}


void insertAtPosition(Node* &head, Node* &tail, int val , int position){
    // 3  case
    // <1  ||  >len     ==> invalid
    // >1 && <len       ==> valid
    int len = findLength(head);
    
    if(position == 1){
        insertAtHead(head, tail, val);
    }
    else if(position == len+1){                // catch
        insertAtTail(head, tail, val);
    }
    else if(position > 1 && position < len){
        // 1->2->4->5
        // 1->2->3->4->5
        Node* prev = nullptr;
        Node* curr = head;

        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }

        Node* newNode = new Node(val);
        newNode->next = curr;
        prev->next = newNode;
    }
    else{
        cout<<"Can't insert, invalid position.";
    }

}




// searching
void searchNode(Node* &head, int target){
    if(!head){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;
    int position = 1;
    while(temp){
        if(temp-> val == target){
            cout<<"Node found at postion : "<<position<<endl;
            return;
        }

        temp = temp->next;
        position++;
    }
}



// Printing Linked list
void printLL(Node* &head){
    Node* temp = head;
    cout<<"Printing Linked list: ";
    while(temp){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"null"<<endl;
}



int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    printLL(head);


    insertAtPosition(head, tail, 30, 3);
    printLL(head);


    searchNode(head, 40);


return 0;
}
// Doubly linked list implementation
// insertion    -> atHead, atTail, atMiddle
// deletion
// searching
// length
// printing

#include<iostream>
using namespace std;

class ListNode{
  public:
    int val;
    ListNode* next;
    ListNode* prev;
    

    ListNode(){
        this->val = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    ListNode(int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
    
};




// insertion
// 1 2  3
void insertAtHead(ListNode* &head, ListNode* &tail, int val){
    ListNode* newNode = new ListNode(val);
    if(!head){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


// 1  2  3  , 4
void insertAtTail(ListNode* &head, ListNode* &tail, int val){
    ListNode* newNode = new ListNode(val);
    if(!head){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


// insertatPostion

int findLength(ListNode* head){
    ListNode* temp = head;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }

   return len;
}


void insertAtPosition(ListNode* &head, ListNode* &tail, int val, int pos){
    int len = findLength(head);
    
    if(pos == 1){
        insertAtHead(head, tail, val);
    }
    else if(pos == len+1){
        insertAtTail(head, tail, val);
    }
    else if(pos > 1 && pos < len){  
        // 1 2   4 5
        // 1 2<->3 4 5
        // 1 2 4 5 -> 6
        ListNode* newNode = new ListNode(val);
        ListNode* prevNode = NULL;
        ListNode* currNode = head;

        while(pos != 1){
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
        }

        prevNode->next = newNode;
        newNode->prev = prevNode;
        currNode->prev = newNode;
        newNode->next = currNode;
    }else{
        cout<<"Can't insert, invalid position.";
    }
}




// Searching
void searchNode(ListNode* &head, int target){
    if(!head){
        cout<<"List is empty"<<endl;
        return;
    }

    ListNode* temp = head;
    int pos = 1;
    bool flag = false;

    while(temp){
        if(temp->val == target){
            flag = true;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if(flag) cout<<"Node found at postion : "<<pos<<endl;
    else cout<<"Node not found"<<endl;
}   



// deleteFromPosition







// printing
void printDLL(ListNode* head){
    ListNode* temp = head;
    int len = 0;
    cout<<"\nPrinitng DLL : ";
    while(temp){
        len++;
        cout<<temp->val<<" -- ";
        temp = temp->next;
    }

    cout<<"x\nLength of DLL : "<<len<<endl;
}





int main(){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtHead(head, tail, 20);       // 20
    insertAtHead(head, tail, 10);       // 10 20

    printDLL(head);

    insertAtTail(head, tail, 40);       // 10 20 40
    insertAtTail(head, tail, 60);       // 10 20 40 60

    printDLL(head);

    insertAtPosition(head, tail, 43, 1);
    insertAtPosition(head, tail, 44, 5);
    insertAtPosition(head, tail, 76, 7);
    insertAtPosition(head, tail, 76, 4);

    printDLL(head);


    searchNode(head, 60);
    searchNode(head, 52);
    searchNode(head, 43);




return 0;
}
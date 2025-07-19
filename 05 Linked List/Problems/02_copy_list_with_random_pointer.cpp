// 138. Copy List with Random Pointer


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//Approach-1 (Using Loop)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        
        // Step1: clone the list linear
        Node* temp1 = head;
        Node* clonedHead = new Node(0);
        Node* temp2 = clonedHead;
        while(temp1){
            Node* newNode = new Node(temp1->val);
            mp[temp1] = newNode;
            temp2->next = newNode;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
    
        // step2: cloned the ranndom pointer
        temp1 = head;
        temp2 = clonedHead->next;
        while(temp1){
            temp2->random = mp[temp1->random];          // catch
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return clonedHead->next;
    }
};



//Approach-2 (Using Recursion)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* newNode = new Node(head->val);
        mp[head] = newNode;

        newNode->next = copyRandomList(head->next);
        newNode->random = mp[head->random];

        return newNode;
    }
};





//Approach-2 (By changing links)
//T.C : O(n)
//S.C : O(1)

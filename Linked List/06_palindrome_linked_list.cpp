// 234. Palindrome Linked List

// Method1: Brute force
class Solution {
public:
    ListNode* replicate(ListNode* head){
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        
        while(head){
            ListNode* temp = new ListNode(head->val);
            tail->next = temp;
            tail = temp;
            head = head->next;
        }

        return dummyHead->next;
    }

    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }


    bool isPalindrome(ListNode* head) {
        ListNode* head2 = replicate(head);
        head2 = reverseLL(head2);

        while(head && head2){
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
};


// Method2: 

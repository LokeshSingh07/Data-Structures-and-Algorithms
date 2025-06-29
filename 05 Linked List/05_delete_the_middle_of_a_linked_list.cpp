// 2095. Delete the Middle Node of a Linked List


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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;                // catch

        while(fast){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
            if(fast) fast = fast->next;
        }


        if(prev == NULL) return NULL;

        prev->next = slow->next;
        slow->next = NULL;
        
        return head;
    }
};


// Same Approach
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast){
            fast = fast->next;
            if(fast){
                prev = slow;
                slow = slow->next;
                fast = fast->next;
            }
        }


        if(prev == NULL) return NULL;

        prev->next = slow->next;
        slow->next = NULL;
        
        return head;
    }
};
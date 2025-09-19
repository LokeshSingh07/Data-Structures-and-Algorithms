// 141. Linked List Cycle


// Method1: using set to store the listNode*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* temp = head;

        while(temp){
            if(st.count(temp)) return true;    

            st.insert({temp});
            temp =  temp->next;
        }

        return false;
    }
};


// Method2: tortoise algo
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast){
            fast = fast->next;
            if(fast){
                slow = slow->next;
                fast = fast->next;
            }

            if(slow == fast) return true;
        }

        return false;
    }
};


// Same approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;

            if(slow == fast) return true;
        }

        return (slow == fast);      // catch
    }
};
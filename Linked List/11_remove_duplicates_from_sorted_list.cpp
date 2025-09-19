// 83. Remove Duplicates from Sorted List


// Method1: Using two pointer
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* curr = head;
        ListNode* temp = head;

        while(temp){
            if(curr->val == temp->val) temp = temp->next;
            else{
                curr = curr->next;
                curr->val = temp->val;
                temp = temp->next;
            }
        }

        curr->next = NULL;
        return head;
    }
};



// Method2: using only single pointer
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
    ListNode* deleteDuplicates(ListNode* head){
        if(!head) return NULL;
        ListNode* temp = head;

        while(temp->next){
            if(temp->val == temp->next->val){
                ListNode* nodeToDel = temp->next;
                temp->next = temp->next->next;
                delete nodeToDel;
            }else{
                temp = temp->next;
            }
        }

        return head;
    }
};
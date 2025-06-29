// 206. Reverse Linked List


// Method1: Iterative
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
};


// Method2: Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};
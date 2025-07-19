// 61. Rotate List


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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            ++len;
            temp = temp->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;

        int L = getLength(head);
        k = k % L;
        if(k==0) return head;

        int remLen = L - k;
        ListNode* temp = head;
        while(remLen != 1){
            temp = temp->next;
            --remLen;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;          // catch
        temp = newHead;
        while(temp->next) temp = temp->next;

        temp->next = head;

        return newHead;
    }
};
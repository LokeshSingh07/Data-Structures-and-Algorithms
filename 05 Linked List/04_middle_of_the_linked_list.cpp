// 876. Middle of the Linked List

// Method1: Brute force
class Solution {
public:
    int findLength(ListNode* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* middleNodeOfLL(ListNode* head, int len){
        int node = len/2;

        while(node--){
            head = head->next;
        }
        return head;
    }

    ListNode* middleNode(ListNode* head) {
        int len = findLength(head);

       return middleNodeOfLL(head, len);
    }
};


// Method2: slow and fast pointer (tortoise algorithm)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }

        return slow;
    }
};
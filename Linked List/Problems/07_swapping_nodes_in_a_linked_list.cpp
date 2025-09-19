// 1721. Swapping Nodes in a Linked List



// Approach-1: (find length, then traverse to kth and (n-k+1)th nodes)
class Solution {
public:
    int getlength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        if(head == 0) return head;

        int pos = getlength(head) - k  +1;

        ListNode* temp1 = head;
        while(k != 1){
            temp1 = temp1->next;
            k--;
        }

        ListNode* temp2 = head;
        while(pos != 1){
            temp2 = temp2->next;
            pos--;
        }

        swap(temp1->val, temp2->val);

        return head;
    }
};
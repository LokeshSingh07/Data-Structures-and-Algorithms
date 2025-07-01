// 19. Remove Nth Node From End of List


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
    int findLength(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = findLength(head);
        int pos = len-n+1;

        // deleteFromHead 
        if(pos==1){
            ListNode* temp = head;
            head = head->next;
            temp->next = 0;
            delete temp;
        }
        else if(pos == len){
            ListNode* curr = head;
            ListNode* prev = NULL;
            while(curr->next){
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL;
            curr->next = NULL;
            delete curr;
        }
        else{
            ListNode* curr = head;
            ListNode* prev = head;
            while(pos > 1){
                prev = curr;
                curr = curr->next;
                pos--;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }

        return head;
    }
};



// Same Approach
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
    int findLength(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = findLength(head);
        int pos = len-n+1;

        // deleteFromHead 
        if(pos==1){
            ListNode* temp = head;
            head = head->next;
            temp->next = 0;
            delete temp;
        }
        else{
            ListNode* curr = head;
            ListNode* prev = head;
            while(pos > 1){
                prev = curr;
                curr = curr->next;
                pos--;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }

        return head;
    }
};
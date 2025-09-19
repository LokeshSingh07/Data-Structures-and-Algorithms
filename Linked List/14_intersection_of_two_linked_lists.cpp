// 160. Intersection of Two Linked Lists

// Method1:
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
    int findLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = findLength(headA);
        int l2 = findLength(headB);

        ListNode* tempA = headA;
        while(l1 > l2){
            l1--;
            tempA = tempA->next;
        }

        ListNode* tempB = headB;
        while(l2 > l1){
            l2--;
            tempB = tempB->next;
        }
    
        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }
};


// method2:
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;

            if(tempA == tempB) return tempA;
            if(!tempA) tempA = headB;
            if(!tempB) tempB = headA;
        }

        return tempA;
    }
};
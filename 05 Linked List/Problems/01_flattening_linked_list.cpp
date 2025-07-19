// Flattening a Linked List


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == 0) return list2;
        if(list2 == 0) return list1;

        ListNode* root = NULL;
        if(list1->val <= list2->val){
            root = list1;
            root->next = mergeTwoLists(list1->next, list2);
        }
        else{
            root = list2;
            root->next = mergeTwoLists(list1, list2->next);
        }

        return root;
    }
};
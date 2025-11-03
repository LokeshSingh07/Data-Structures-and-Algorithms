// 23. Merge k Sorted Lists


// Approach-1: merge two list k times
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
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* result = NULL;
        if(l1->val <= l2->val){
            result = l1;
            result->next = merge(l1->next, l2);
        }
        else{
            result = l2;
            result->next = merge(l1, l2->next);
        }
        return result;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return nullptr;

        ListNode* result = NULL;
        for(int i=0; i<k; i++){
            result = merge(result, lists[i]);
        }

        return result;
    }
};



// Approach-2: using heap
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
struct Comparator{
    bool operator()(ListNode* &a, ListNode* &b){
        return a->val > b->val;             // min-heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;

        // put the first k node of the list in the heap
        for(int k=0; k<lists.size(); k++){
            if(lists[k]) pq.push(lists[k]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!pq.empty()){
            ListNode* topNode = pq.top();
            pq.pop();

            temp->next = topNode;
            temp = temp->next;
            if(topNode->next) pq.push(topNode->next);
        }
    
        return dummy->next;
    }
};
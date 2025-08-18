// 2816. Double a Number Represented as a Linked List



// Approach-1: (reverse + double digits with carry, reverse back)
class Solution {
public:
    ListNode* reverse(ListNode* &root){
        if(!root || !root->next) return root;

        ListNode* newHead = reverse(root->next);
        root->next->next = root;                    // catch
        root->next = nullptr;

        return newHead;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        int carry = 0;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp){
            int sum = (temp->val * 2) + carry;
            temp->val = sum % 10;
            carry = sum / 10;
            
            prev = temp;
            temp = temp->next;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }

        return reverse(head);
    }
};




// Approach-2: (Using Backtracking update the node)
class Solution {
public:
    void solve(ListNode* &head, int &carry){
        if(!head) return;
        solve(head->next, carry);

        int sum = head->val*2 + carry;
        head->val = sum % 10;
        carry = sum / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = 0;

        solve(head, carry);

        if(carry){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
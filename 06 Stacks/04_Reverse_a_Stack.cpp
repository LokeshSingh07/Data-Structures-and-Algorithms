// Reverse a stack


// Approach-1: Using stack
class Solution {
  public:
    void reverse(stack<int> &St) {
        stack<int> temp;
        
        while(!St.empty()){
            int x = St.top();
            St.pop();
            temp.push(x);
        }
            
        St = temp;
    }
};


// Approach-2: Using stack
class Solution {
  public:
    void reverse(stack<int> &st) {
        if(st.empty()) return;
            
        int top = st.top();
        st.pop();
        reverse(st);
        
        stack<int> temp;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            temp.push(x);
        }
        
        st.push(top);
        while(!temp.empty()){
            int x = temp.top();
            temp.pop();
            st.push(x);
        }
        
    }
};


// Approach-3: insertAtBottom

class Solution {
  public:
    void insertAtBottom(stack<int> &st, int &x){
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int temp = st.top();
        st.pop();
        insertAtBottom(st, x);
        
        st.push(temp);
    }
  
    void reverse(stack<int> &st) {
        if(st.empty()) return;
        
        int x = st.top();
        st.pop();
        reverse(st);
        
        insertAtBottom(st, x);
    }
};

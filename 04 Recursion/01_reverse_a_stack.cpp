// Reverse a Stack

// Method 1: Using Auxilary space
class Solution {
  public:
    void Reverse(stack<int> &st) {
        if(st.empty()) return;
        
        int top = st.top();
        st.pop();
        Reverse(st);
        
        // 
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        
        st.push(top);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }

    }
};


// Method 2: W/O using auxilary space  --> TC: O(n^2)
class Solution {
  public:
    void insertAtBottom(stack<int> &st, int element){
        if(st.empty()){
            st.push(element);
            return;
        }
        
        int top = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(top);
    }
  
    void Reverse(stack<int> &st){
        if(st.empty()) return; 
        
        int top = st.top();
        st.pop();
        Reverse(st);
        
        insertAtBottom(st, top);
    }
};
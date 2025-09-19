// Insert an Element at the Bottom of a Stack


class Solution {
  public:
    void insertBottom(stack<int> &st, int &x){
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int top = st.top();
        st.pop();
        insertBottom(st, x);
        
        st.push(top);
    }
    
    stack<int> insertAtBottom(stack<int> st, int x) {
        insertBottom(st, x);
        return st;
    }
};
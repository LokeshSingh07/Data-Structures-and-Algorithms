// Delete Mid of a Stack
// Middle element of a stack 

class Solution {
  public:
    // Function to delete middle element of a stack.
    void solve(stack<int> &st, int curr, int &n){
        if(curr == n/2){
            st.pop();
            return;
        }
        
        int x = st.top();
        st.pop();
        solve(st, curr+1, n);
        
        st.push(x);
    }
    
    void deleteMid(stack<int>& st) {
        int n = st.size();
        solve(st, 0, n);
    }
};
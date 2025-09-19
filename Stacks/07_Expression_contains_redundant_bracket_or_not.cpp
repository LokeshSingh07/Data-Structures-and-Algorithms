// Expression contains redundant bracket or not

class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;
            
        for(auto ch: s){
            if(ch=='(' || ch == '+' || ch=='-' || ch=='*' || ch=='/') st.push(ch);
            else if(ch==')'){
                if(st.top() == '(') return true;
                
                while(!st.empty() && st.top() != '(') 
                    st.pop();
                st.pop();
            }
        }
        
        return false;
    }
};
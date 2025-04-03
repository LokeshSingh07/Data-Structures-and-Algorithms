// 1047. Remove All Adjacent Duplicates In String

// Method 1: Using stack
class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        stack<int> st;
        int i = 0;

        while(s[i] != '\0'){
            char ch = s[i];
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
            i++;
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};


// Method 2: Without using extra space
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string temp = "";

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(temp.length() > 0 && temp.back() == ch) temp.pop_back();
            else temp.push_back(ch);
        }

        return temp;
    }
};
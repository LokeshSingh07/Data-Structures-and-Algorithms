// 394. Decode String

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for(auto ch: s){
            if(ch == ']'){
                // create stringto repeat
                string str = "";
                while(!st.empty() && st.top() != "["){
                    str += st.top();
                    st.pop();
                }
                st.pop();

                // create numberOfTimes it repear
                string num = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    num += st.top();
                    st.pop();
                }
                reverse(begin(num), end(num));
                int n = stoi(num);

                // create decoded string
                string decodedStr = "";
                while(n--){
                    decodedStr += str;
                }

                st.push(decodedStr);
            }
            else{
                string temp = "";
                temp += ch;
                st.push(temp);
            }
        }

        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(begin(result), end(result));

        return result;
    }
};
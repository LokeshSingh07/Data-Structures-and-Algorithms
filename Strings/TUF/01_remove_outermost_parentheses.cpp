// 1021. Remove Outermost Parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int count=0;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];

            if(ch == '('){
                if(count != 0) result.push_back(ch);
                count++;
            }
            else{
                count--;
                if(count != 0) result.push_back(ch);
            }
        }
        return result;
    }
};
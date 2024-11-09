// 1047. Remove All Adjacent Duplicates In String

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string temp = "";

        for(int i=0; i<n; i++){
            if(temp.length() > 0 && (s[i] == temp[temp.length()-1])) temp.pop_back();
            else temp.push_back(s[i]);
        }

        return temp;
    }
};
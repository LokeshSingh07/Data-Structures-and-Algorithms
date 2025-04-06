// 917. Reverse Only Letters

class Solution {
public:
    bool isAlpha(char ch){
        return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
    }

    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i=0;
        int j = n-1;

        while(i<j){
            if(!isAlpha(s[i])) i++;
            else if(!isAlpha(s[j])) j--;
            else{
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};
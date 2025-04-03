// 680. Valid Palindrome II

class Solution {
public:
    bool checkPalin(string str, int s, int e){
        while(s < e){
            if(str[s] != str[e]) return false;
            s++;
            e--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0 ;
        int r = n-1;

        while(l < r){
            if(s[l] != s[r]){
                bool p1 = checkPalin(s, l+1, r);
                bool p2 = checkPalin(s, l, r-1);
                return p1 || p2;
            }
            l++;
            r--;
        }

        return true;
    }
};
// 680. Valid Palindrome II

class Solution {
public:
    bool checkPalindrome(string s, int l, int r){
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;

        while(l<r){
            if(s[l] != s[r]){
                // 1 removal
                bool ans1 = checkPalindrome(s, l+1, r);        // ith ko remove kiya h
                bool ans2 = checkPalindrome(s, l, r-1);        // jth ko remove kiya h
                return ans1 || ans2;
            }
            l++;
            r--;
        }

        return true;
    }
};
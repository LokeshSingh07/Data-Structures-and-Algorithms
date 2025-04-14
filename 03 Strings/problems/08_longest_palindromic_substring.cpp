// 5. Longest Palindromic Substring

// Method 1: Brute force        --      TLE
class Solution {
public:
    bool isPalindrome(string &s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string result = "";

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string temp = s.substr(i, j-i+1);
                if(isPalindrome(temp) && temp.size() > result.size()){
                    result = temp;
                }
            }
        }

        return result;
    }
};


// Method 1: optimised
class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string result = "";

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s, i, j)){
                    string temp = s.substr(i, j-i+1);
                    result = temp.size() > result.size() ? temp : result;
                }
            }
        }

        return result;
    }
};
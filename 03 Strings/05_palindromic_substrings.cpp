// 647. Palindromic Substrings

// Method 1: 
class Solution {
public:
    bool checkPalindrome(string s){
        int n = s.size();
        int l=0, r=n-1;
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<string> st;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                st.push_back(s.substr(i, j-i+1));
            }
        }

        // check for plaindrome
        int count = 0;
        for(auto &it: st){
            if(checkPalindrome(it)){
                count++;
            }
        }

        return count;
    }
};


// Method 2: 

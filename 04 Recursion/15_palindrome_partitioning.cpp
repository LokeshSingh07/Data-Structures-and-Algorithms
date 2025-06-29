// 131. Palindrome Partitioning

class Solution {
public:
    vector<vector<string>> result;
    int n;

    bool isPalindrome(string &str, int s, int e){
        while(s<e){
            if(str[s++] != str[e--]) return false;
        }
        return true;
    }

    void solve(string &s, int idx, vector<string> &temp){
        if(idx >= n){
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<n; i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(s, i+1, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> temp;
        int idx = 0;
        solve(s, idx, temp);

        return result;
    }
};
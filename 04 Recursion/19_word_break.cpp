// 139. Word Break

class Solution {
public:
    int t[301];
    bool solve(string &s, int idx, unordered_set<string> &st){
        if(idx >= s.size()) return true;
        if(st.count(s.substr(idx))) return true;

        if(t[idx] != -1) return t[idx];

        for(int l=1; l<=s.size(); l++){
            string temp = s.substr(idx, l);
            if(st.count(temp) && solve(s, idx+l, st)){
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t, -1, sizeof(t));
        unordered_set<string> st;
        
        for(auto word: wordDict){
            st.insert(word);
        }

        return solve(s, 0, st);
    }
};
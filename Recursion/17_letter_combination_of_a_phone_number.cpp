// 17. Letter Combinations of a Phone Number

class Solution {
public:
    void solve(string digits, int idx, unordered_map<char,string> &mp, vector<string> &result, string temp){
        if(idx == digits.size()){
            result.push_back(temp);
            return;
        }

        char ch = digits[idx];
        for(auto it: mp[ch]){
            temp.push_back(it);
            solve(digits, idx+1, mp, result, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> result;
        string temp = "";

        if(digits.size() == 0) return {};
        
        solve(digits, 0, mp, result, temp);
        return result;
    }
};
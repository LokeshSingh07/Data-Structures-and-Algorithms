// 890. Find and Replace Pattern    --    [Prerequisite: 205. Isomorphic Strings]


class Solution {
public:
    string isomorphic(string &s){
        vector<char> mp(26, ' ');
        string temp = "";
        char ch = 'a';
        for(char c : s){
            if(mp[c-'a'] == ' '){
                mp[c-'a'] = ch;
                ch++;
            }
            temp.push_back(mp[c-'a']);
        }
        return temp;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        pattern = isomorphic(pattern);

        for(string word: words){
            if(isomorphic(word) == pattern){
                ans.push_back(word);
            }
        }

        return ans;
    }
};
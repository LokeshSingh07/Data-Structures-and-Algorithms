// 890. Find and Replace Pattern

class Solution {
public:
    void createMapping(string& s){
        unordered_map<char, char> mp;
        char code = 'a';

        for(char ch: s){
            if(mp.find(ch) == mp.end()){
                // not present
                mp[ch] = code;
                code++;
            }
        }

        // update the string with pattern abc
        for(char &ch : s){
            ch = mp[ch];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        createMapping(pattern);

        for(string s : words){
            string  tempStr = s;

            createMapping(tempStr);

            if(tempStr == pattern){
                ans.push_back(s);
            }
        }

        return ans;
    }
};
// 2325. Decode the Message

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        string ans = "";
        int n = key.size();
        char code = 'a';
        mp[' '] = ' ';

        for(char ch: key){
            if(mp.find(ch) == mp.end()){
                // not present
                mp[ch] = code;
                code++;
            }
        }


        for(char ch: message){
            ans.push_back(mp[ch]);
        }

        return ans;
    }
};
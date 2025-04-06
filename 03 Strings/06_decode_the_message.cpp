// 2325. Decode the Message

class Solution {
public:
    string decodeMessage(string key, string message) {
        int n = key.size();
        vector<char> freq(26, ' ');
        string result = "";

        // create mapping
        char ch = 'a';
        for(char c: key){
            if(c != ' ' &&  freq[c-'a'] == ' '){
                freq[c-'a'] = ch;
                ch++;
            }
        }

        // decode
        for(int i=0; i<message.size(); i++){
            ch = message[i];
            if(ch == ' ') result.push_back(ch);
            else result.push_back(freq[ch-'a']);
        }

        return result;
    }
};
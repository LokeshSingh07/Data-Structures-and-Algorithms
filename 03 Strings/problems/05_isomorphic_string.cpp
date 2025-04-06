// 205. Isomorphic Strings

class Solution {
public:
    string createMapping(string s){
        unordered_map<char,char> mp;
        string temp = "";
        char ch = 'a';
        for(auto c : s){
            if(mp.find(c) == mp.end()){
                mp[c] = ch;
                ch++;
            }
            temp.push_back(mp[c]);
        }
        return temp;
    }

    bool isIsomorphic(string s, string t) {
        string str1 = createMapping(s);
        string str2 = createMapping(t);

        return str1==str2;
    }
};
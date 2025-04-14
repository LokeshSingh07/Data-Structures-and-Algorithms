// 49. Group Anagrams

// Method 1: sorting  + mapping
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto &s: strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }

        vector<vector<string>> result;
        for(auto it: mp){
            result.push_back(it.second);
        }

        return result;
    }
};


// Method 2: mapping (better soln) 
class Solution {
public:
    vector<int> createMapping(string s){
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++; 
        }
        return freq;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;

        for(auto s: strs){
            mp[createMapping(s)].push_back(s);
        }

        vector<vector<string>> result; 
        for(auto it: mp){
            result.push_back(it.second);
        }

        return result;
    }
};
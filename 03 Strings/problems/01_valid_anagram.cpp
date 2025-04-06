// 242. Valid Anagram


// Method 1: Sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(begin(s), end(s));
        sort(begin(t), end(t));

        return s == t;
    }
};


// Method 2: Hashmap
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);

        // tarverse the string s
        for(auto ch : s){
            freq[ch-'a']++;
        }

        // tarverse the string t
        for(auto ch : t){
            freq[ch-'a']--;
        }

        // check if freq of all char is 0 or not
        for(int i=0; i<26; i++){
            if(freq[i] != 0) return false;
        }

        return true;
    }
};
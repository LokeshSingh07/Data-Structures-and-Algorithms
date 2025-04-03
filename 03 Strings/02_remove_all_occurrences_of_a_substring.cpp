// 1910. Remove All Occurrences of a Substring


// Method 1: Using inbuilt methods
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};


// Method 2: Using stack

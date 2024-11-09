// 647. Palindromic Substrings

class Solution {
public:
    int expand(string s, int i, int j){
        int count = 0;
        while(i>=0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
            count++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int total = 0;

        for(int i=0; i<n; i++){
            int odd = expand(s, i, i);
            int even = expand(s, i, i+1);
            total += (odd+even);
        }

        return total;
    }
};
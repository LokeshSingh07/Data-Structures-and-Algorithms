// 151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        reverse(begin(s), end(s));
        
        int n = s.size();
        int left = 0;
        int right = 0;
        int j = 0;

        while(j < n){
            while(j<n && s[j] == ' ') j++;
            if(j == n) break;

            while(j<n && s[j] != ' '){
                s[right++] = s[j++];        // shift
            }
            
            reverse(begin(s)+left, begin(s)+right);
            
            s[right] = ' ';
            right++;
            left = right;
            
        }
        s.resize(right-1);

        return s;
    }
};
// 443. String Compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0, j=0;

        while(j<n){
            char curr_ch = chars[j];
            int count = 0;

            while(j<n && curr_ch == chars[j]){
                count++;
                j++;
            }

            chars[i] = curr_ch;
            i++;
            if(count > 1){
                string cnt = to_string(count);
                for(auto ch: cnt){
                    chars[i++] = ch;
                }
            }
        }

        return i;
    }
};
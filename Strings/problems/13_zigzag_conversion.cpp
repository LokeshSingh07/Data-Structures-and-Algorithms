// 6. Zigzag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<string> zigzag(numRows);
        int dir = 1;  // T->B
        int row = 0;
        int i=0;
        
        while(i<n){
            if(dir){
                while(row < numRows && i<n){
                    zigzag[row].push_back(s[i]);
                    row++;
                    i++;
                }
                row = numRows -2;
            }
            else{
                while(row>0 && i<n){
                    zigzag[row].push_back(s[i]);
                    row--;
                    i++;
                }
                row = 0;
            }
            dir = !dir;
        }

        string result = "";
        for(auto temp : zigzag){
            result += temp;
        }

        return result;
    }
};
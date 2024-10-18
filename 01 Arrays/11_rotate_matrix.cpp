// 48. Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();

        // transpose
        for(int i=0; i<m; i++){
            for(int j=i; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse every row
        for(int i=0; i<m; i++){
            // reverse
            int s = 0;
            int e = m-1;
            while(s < e){
                swap(matrix[i][s++], matrix[i][e--]);
            }
        }
    }
};
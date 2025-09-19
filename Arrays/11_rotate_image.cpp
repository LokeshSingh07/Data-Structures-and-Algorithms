// 48. Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // transpose
        for(int i=0; i<m; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse every row
        for(int i=0; i<n; i++){
            int s = 0;
            int e = n-1;
            while(s < e){
                swap(matrix[i][s++],matrix[i][e--]);
            }
        }
    }
};
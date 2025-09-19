// 74. Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int e = m*n - 1;    // catch

        while(s<=e){
            int mid = s+(e-s)/2;
            int rowIdx = mid/n;
            int colIdx = mid%n;

            if(matrix[rowIdx][colIdx] == target) return true;
            else if(matrix[rowIdx][colIdx] < target) s = mid+1;
            else e = mid-1;
        }

        return false;
    }
};
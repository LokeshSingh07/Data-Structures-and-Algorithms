// 74. Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row*col;

        int s = 0;
        int e = n-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            
            int rowIndex = mid / col; 
            int colIndex = mid % col;
            
            if(matrix[rowIndex][colIndex] == target) return true;
            else if(matrix[rowIndex][colIndex] < target) s = mid+1;
            else e = mid-1;
        }

        return false;
    }
};


/*
    1D --> 2D conversion
    Formula: 
        i = mid / C
        j = mid % C

    where i,j is index & C is no of column 
*/
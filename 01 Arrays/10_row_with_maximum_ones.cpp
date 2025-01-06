// 2643. Row With Maximum Ones

// Method 1: Brute Force
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans(2);
        int maxi = INT_MIN;

        for(int i=0; i<m; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(mat[i][j]) count++;
            }

            if(count > maxi){
                maxi = count;
                ans[0] = i;
                ans[1] = count;
            }
        }
        return ans;
    }
};
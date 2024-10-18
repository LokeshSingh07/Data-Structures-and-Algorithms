// 2643. Row With Maximum Ones

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2);

        for(int i=0; i<mat.size(); i++){
            int cnt = 0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]) cnt++; 
            }

            if(cnt > ans[1]){
                ans[0] = i;
                ans[1] = cnt;
            }
        }

        return ans;
    }
};
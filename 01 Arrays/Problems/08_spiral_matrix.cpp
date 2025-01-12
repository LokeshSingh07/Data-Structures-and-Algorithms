// Spiral Matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top=0, down=m-1, left=0, right=n-1;
        int dir=1;
        vector<int> ans;

        while(left<=right && top<=down){
            if(dir==1){
                for(int i=left; i<=right; i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir==2){
                for(int i=top; i<=down; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir==3){
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            else{
                for(int i=down; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }

            dir = (dir+1)%4;
        }

        return ans;
    }
};
// 42. Trapping Rain Water


// Approach-1: 
class Solution {
public:
    void leftMax(vector<int> &height, vector<int> &result){
        int n = height.size();
        result[0] = height[0];

        for(int i=1; i<n; i++){
            result[i] = max(height[i], result[i-1]);
        }
    }

    void rightMax(vector<int> &height, vector<int> &result){
        int n = height.size();
        result[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--){
            result[i] = max(height[i], result[i+1]);
        }
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        leftMax(height, left);
        rightMax(height, right);

        int trapWater = 0;

        for(int i=0; i<n; i++){
            trapWater += min(left[i], right[i]) - height[i];
        }

        return trapWater;
    }
};




// Approach-2: 

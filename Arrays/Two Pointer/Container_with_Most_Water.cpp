// 11. Container With Most Water


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWaterTrap = 0;
        int i=0, j=n-1;

        while(i < j){
            int h = min(height[i], height[j]);
            int w = j-i;
            int water = h*w;
            maxWaterTrap = max(maxWaterTrap, water);

            if(height[i] < height[j]) i++;
            else j--;
        }

        return maxWaterTrap;
    }
};
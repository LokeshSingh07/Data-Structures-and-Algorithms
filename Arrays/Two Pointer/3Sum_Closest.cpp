// 16. 3Sum Closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = 0;
        int minDiff = INT_MAX;

        for(int i=0; i<n-2; i++){
            int s = i+1;
            int e = n-1;
            
            while(s < e){
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == target) return sum;
                else if(sum < target) s++;
                else e--;

                int diff = abs(sum - target);
                if(diff < minDiff){
                    result = sum;
                    minDiff = diff;
                }
            }
        }

        return result;
    }
};
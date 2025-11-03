// 18. 4Sum


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> se;
        vector<vector<int>> result;

        sort(begin(nums), end(nums));

        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long sum = nums[i] + nums[j];
                int s = j+1;
                int e = n-1;

                while(s < e){
                    long long tempSum = sum + nums[s] + nums[e];
                    if(tempSum == target){
                        se.insert({nums[i], nums[j], nums[s], nums[e]});
                        s++;
                        e--;
                    }
                    else if(tempSum > target) e--;
                    else s++;
                }
            }
        }


        for(auto P: se){
            result.push_back(P);
        }

        return result;
    }
};
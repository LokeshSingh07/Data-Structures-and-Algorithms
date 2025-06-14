// 78. Subsets

class Solution {
public:
    vector<vector<int>> result;
    
    void solve(vector<int> &nums, int i, vector<int> &curr){
        if(i >= nums.size()){
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, i+1, curr);
        curr.pop_back();

        solve(nums, i+1, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(nums, 0, curr);

        return result;
    }
};
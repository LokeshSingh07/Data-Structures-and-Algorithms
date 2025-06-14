// 46. Permutations


class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(vector<int> &nums, int idx, vector<int> &curr){
        if(idx >= n){
            result.push_back(curr);
            return;
        }

        // do, explore, undo
        for(int i=0; i<n; i++){
            if(find(begin(curr), end(curr), nums[i]) == end(curr)){ // not present
                curr.push_back(nums[i]);
                solve(nums, idx+1, curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        solve(nums, 0, curr);
        return result;
    }
};
// 47. Permutations II

class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(vector<int> &nums, int i, unordered_map<int,int> &mp, vector<int> &curr){
        if(i >= n){
            result.push_back(curr);
            return;
        }

        for(auto it : mp){
            if(it.second > 0){
                mp[it.first]--;
                curr.push_back(it.first);
                solve(nums, i+1, mp, curr);
                curr.pop_back();
                mp[it.first]++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int,int> mp;
        vector<int> curr;

        // create mapping
        for(auto it: nums){
            mp[it]++;
        }
        
        solve(nums, 0, mp, curr);

        return result;
    }
};
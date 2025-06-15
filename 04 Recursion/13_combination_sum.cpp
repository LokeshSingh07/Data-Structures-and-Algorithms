// 39. Combination Sum

class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int> &candidates, int idx, int &target, int currSum, vector<int> &temp){
        // base case
        if(target == currSum){
            result.push_back(temp);
            return;
        }

        if(currSum > target || idx >= candidates.size()) return;


        temp.push_back(candidates[idx]);
        solve(candidates, idx, target, currSum+candidates[idx], temp);
        temp.pop_back();

        solve(candidates, idx+1, target, currSum, temp);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int currSum = 0;
        int idx = 0;

        solve(candidates, idx, target, currSum, temp);
        return result;
    }
};
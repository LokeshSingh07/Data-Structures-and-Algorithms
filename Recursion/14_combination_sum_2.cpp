// 40. Combination Sum II

class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int> &candidates, int idx, int target, vector<int> &temp){
        if(target < 0) return;
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            temp.push_back(candidates[i]);
            solve(candidates, i+1, target-candidates[i], temp);
            temp.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(begin(candidates), end(candidates));

        solve(candidates, 0, target, temp);    
    
        return result;
    }
};
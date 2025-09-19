// 77. Combinations

class Solution {
public:
    vector<vector<int>> result;

    void solve(int n, int idx, int k, vector<int> &temp){
        if(k == 0){
            result.push_back(temp);
            return;
        }

        if(idx > n) return;

        // include
        temp.push_back(idx);
        solve(n, idx+1, k-1, temp);
        temp.pop_back();

        // exclude
        solve(n, idx+1, k, temp);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        int idx = 1;

        solve(n, idx, k, temp);

        return result; 
    }
};
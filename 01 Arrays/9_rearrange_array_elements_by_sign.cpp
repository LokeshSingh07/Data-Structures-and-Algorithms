// 2149. Rearrange Array Elements by Sign  [https://leetcode.com/problems/rearrange-array-elements-by-sign/]

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1, v2;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int ele = nums[i];
            if(ele > 0) v1.push_back(ele);
            else v2.push_back(ele);
        }

        vector<int> ans;
        for(int i=0; i<v1.size(); i++){
            ans.push_back(v1[i]);
            ans.push_back(v2[i]);
        }

        return ans;
    }
};
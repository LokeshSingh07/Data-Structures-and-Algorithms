// 1. Two Sum

// Method 1: Brute Force
class Solution {
public:
    vector<int> solve(vector<int> &nums, int target){
        int n = nums.size();

        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                if(nums[i]+nums[j] == target) return {i, j};
            }
        }

        return {};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // Method1: naive 
        return solve(nums, target);
    }
};


// Method 2: Hash Table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            int comp = target - nums[i];
            if(mp.find(comp) != mp.end()){
                // present
                return {mp[comp], i};
            }

            mp[nums[i]] = i;
        }
        return {};
    }
};
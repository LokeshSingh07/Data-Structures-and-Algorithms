// 560. Subarray Sum Equals K


// Approach-1: Brute force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum == k) count++;
            }
        }

        return count;
    }
};



// Approach-2: Optimal
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int count=0, sum=0;
        mp.insert({0,1});

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()) count += mp[sum-k];
            mp[sum]++;
        }

        return count;
    }
};
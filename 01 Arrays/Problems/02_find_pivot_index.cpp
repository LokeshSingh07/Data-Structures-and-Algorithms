// 724. Find Pivot Index

// Method 1 : Brute Force
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int lSum=0, rSum=0;
            for(int j=0; j<i; j++) lSum += nums[j];
            for(int j=i+1; j<n; j++) rSum += nums[j];
            if(lSum == rSum) return i;
        }

        return -1;
    }
};


// Method 2 : Prefix Sum / Cumulative Sum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> postfix(n, 0);
        
        // pre-compute prefix
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        // pre-compute postfix
        postfix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            postfix[i] = postfix[i+1] + nums[i];
        }

        // compare prefix & postfix val
        for(int i=0; i<n; i++){
            if(prefix[i] == postfix[i]) return i; 
        }

        return -1;
    }
};
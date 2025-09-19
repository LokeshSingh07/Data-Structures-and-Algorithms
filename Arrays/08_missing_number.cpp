// 268. Missing Number

// Method 1: Using Sum
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = (n*(n+1))/2;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        return (totalSum - sum);
    }
};

// Method 2: Using XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorTotal = 0;
        int xorNums = 0;

        for(int i=0; i<=n; i++) xorTotal ^= i;

        for(int i=0; i<n; i++) xorNums ^= nums[i];

        return (xorTotal ^ xorNums);
    }
};
// 268. Missing Number  [https://leetcode.com/problems/missing-number/]

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int numsSum = accumulate(begin(nums), end(nums), 0);
        
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += i;
        }

        return sum - numsSum;
    }
};
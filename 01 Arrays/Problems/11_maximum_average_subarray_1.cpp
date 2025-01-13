// Maximum Average Subarray I

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = INT_MIN;
        int n = nums.size();
        int i=0, j=0;
        double sum = 0;

        while(j<n){
            sum += nums[j];
            
            if(j-i+1 == k){
                maxSum = max(maxSum, sum);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return maxSum/(double)k;
    }
};
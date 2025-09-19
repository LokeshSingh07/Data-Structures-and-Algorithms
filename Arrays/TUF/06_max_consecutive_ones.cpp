// 485. Max Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int len=0, tempLen=0;
        int i=0;
        int j=0;

        while(j<n){
            if(nums[j]){
                tempLen = j-i+1;
                len = max(len, tempLen);
            }
            else{
                i=j+1;
            }
            j++;
        }

        return len;
    }
};
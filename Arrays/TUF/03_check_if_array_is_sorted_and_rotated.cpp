// 1752. Check if Array Is Sorted and Rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count=0;

        for(int i=0; i<n; i++){
            int idx = (i+1)%n;
            if(nums[i] > nums[idx]) count++;
        }

        return (count>1) ? false : true;
    }
};
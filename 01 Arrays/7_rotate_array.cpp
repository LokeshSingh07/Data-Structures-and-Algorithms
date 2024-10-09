// 189. Rotate Array  [https://leetcode.com/problems/rotate-array/]

// TLE
class Solution {
public:
    void shiftBy1(vector<int> &nums){
        int n = nums.size();
        int temp = nums[n-1];
        for(int i=n-1; i>0; i--){
            nums[i] = nums[i-1];
        } 
        nums[0] = temp;
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        while(k--)
            shiftBy1(nums);
    }
};
// TC: O(n*k)



// Modulus
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            int index = (i+k)%n;
            ans[index] = nums[i];
        }

        nums = ans;
    }
};
// TC: O(n)
// SC: O(n)
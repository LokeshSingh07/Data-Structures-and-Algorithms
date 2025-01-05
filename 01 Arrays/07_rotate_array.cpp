// 189. Rotate Array

// Method 1: Using Extra Array
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


// Method 2: Using Reverse
class Solution {
public:
    void rotate(vector<int>& nums, int k){
        int n = nums.size();
        k = k % n;

        // reverse the arr
        reverse(begin(nums), end(nums));

        // reverse first k elements
        reverse(begin(nums), begin(nums)+k);

        // reverse remaining element except first k elements
        reverse(begin(nums)+k, end(nums));

    }
};
// 283. Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;

        while(j<n){
            if(nums[j]){        // mistake -> not equal to 0 wali condition phle likhni thi
                swap(nums[i++], nums[j++]);
            }
            else j++;
        }
    }
};
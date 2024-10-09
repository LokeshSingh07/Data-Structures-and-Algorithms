// 75. Sort Colors  [https://leetcode.com/problems/sort-colors/]

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int index=0;

        while(index <= r){
            if(nums[index] == 0){
                swap(nums[l], nums[index]);
                l++;
                index++;
            }
            else if(nums[index] == 1) index++;
            else{
                swap(nums[r], nums[index]);
                r--;    
            }
        }
    }
};



/*
    Approaches
    1. Sorting
    2. two pointer

*/
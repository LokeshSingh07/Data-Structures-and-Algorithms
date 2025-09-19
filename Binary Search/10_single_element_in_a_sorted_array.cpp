//  540. Single Element in a Sorted Array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid;
        
        while(s <= e){
            mid = s+(e-s)/2;
            if((mid>0 && mid<n-1 && nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) || s==e) return nums[mid];
            // check for odd
            if(mid & 1){
                if(mid < n-1 && nums[mid] == nums[mid+1]) e = mid-1;
                else s = mid+1;
            }
            else{
                if(mid > 0 && nums[mid] == nums[mid+1]) s = mid+2;
                else e = mid-2;
            }
        }

        return -1;
    }
};
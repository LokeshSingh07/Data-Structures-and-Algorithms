// 33. Search in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target) return mid;
            // left sorted h --> 
            else if(nums[s] <= nums[mid]){
                if(nums[s] <= target && nums[mid]>=target) e = mid-1;
                else s = mid+1;
            }
            else{
                if(nums[mid]<=target && nums[e]>=target) s = mid+1;
                else e = mid-1;
            }
        }

        return -1;
    }
};





/*
    Time Complexity: O(log n)

    12,14,16,2,4,6,8,10
    
    |
    |           (16) pivot
    |       14
    |   12 
    |--------------------------------------
    |                               10
    |                           8
    |                       6
    |                   4
    |               2
    |__________________________________________________

    We have considered maximum element (16) as PIVOT

*/
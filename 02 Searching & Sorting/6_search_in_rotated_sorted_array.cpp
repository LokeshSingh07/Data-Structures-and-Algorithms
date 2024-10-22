// 33. Search in Rotated Sorted Array

class Solution {
public:
    int pivotIndex(vector<int> &nums){  
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid = s+(e-s)/2;

        while(s<=e){
            if(s==e) return s;      // catch

            // handle pivot separately
            if(mid+1 < n && nums[mid] > nums[mid+1])        // catch(Array out of bound) => (mid+1 < n), (mid-1 >= 0)
                return mid;
            else if(mid-1 >= 0 && nums[mid] < nums[mid-1])
                return mid-1;

            // check for partition whether the mid is above or below the line
            else if(nums[s] > nums[mid]) 
                e = mid-1;                  // left me jao
            else 
                s = mid+1;                  // right me jao 

            // mid update
            mid = s+(e-s)/2;
        }

        return -1;
    }

    int binarySearch(vector<int> &nums, int start, int end, int target){
        int s=start;
        int e=end;
        
        while(s <= e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) s = mid+1;
            else e = mid-1;
        }

        return -1;
    }


    int search(vector<int>& nums, int target) {
        int pivot = pivotIndex(nums);
        cout<<pivot<<endl;
        int e = nums.size()-1;
        int idx = -1;
        
        if(target >= nums[0] && target <= nums[pivot]){     // Line A
            idx = binarySearch(nums, 0, pivot, target);
        }
        else{                                               // Line B
            idx = binarySearch(nums, pivot+1, e, target);
        }

        return idx;
    }
};
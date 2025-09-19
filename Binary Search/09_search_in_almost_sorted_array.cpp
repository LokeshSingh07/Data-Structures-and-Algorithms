// Search in an almost Sorted Array

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        
        while(s <= e){
            int mid = s+(e-s)/2;
            if(arr[mid] == target) return mid;
            if(mid > 0 && arr[mid-1] == target) return mid-1;
            if(mid <n-1 && arr[mid+1] == target) return mid+1;
            else if(arr[mid] > target){
                e = mid-1;
            }
            else s = mid+1;
        }
            
        return -1;
    }
};
// Allocate Minimum Pages

class Solution {
  public:
  
    bool canPossible(vector<int> &nums, int k, int mid){
        int studentCount = 1;
        int pageSum = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > mid) return false;         // catch
            if(pageSum + nums[i] <= mid){
                pageSum += nums[i];
            }
            else{
                studentCount++;
                pageSum = nums[i];
            }
        }
        
        return studentCount <= k; 
    }
  
    int findPages(vector<int> &arr, int k){
        if(arr.size() < k) return -1;
        
        int s = 0;
        int e = accumulate(begin(arr), end(arr), 0);
        int result = -1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(canPossible(arr, k, mid)){
                result = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return result;
    }
};
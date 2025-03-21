// The Painter's Partition Problem

class Solution {
  public:
    bool isPossible(vector<int>&nums, int k, int mid){
        int painterCount = 1;
        int timeToPaintBoard = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > mid) return false;     // catch
            if(timeToPaintBoard + nums[i] <= mid){
                timeToPaintBoard += nums[i];
            }
            else{
                painterCount++;
                timeToPaintBoard = nums[i];
            }
            if(painterCount > k) return false;
        }
        
        return true;
    }
  
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        int s = *max_element(begin(arr), end(arr));
        int e = accumulate(begin(arr), end(arr), 0);
        
        if(k>n) return s;
        int result = -1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(arr, k, mid)){
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
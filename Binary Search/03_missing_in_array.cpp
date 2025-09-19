// Missing in Array

class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        
        int s = 0;
        int e = n-1;
        int mid = s+(e-s)/2;
        
        while(s <= e){
            int diff = abs(mid - arr[mid]);
            if(diff > 1){
                e = mid-1;
            }
            else s = mid+1;
        
            mid = s+(e-s)/2;
        }
        
        return mid+1;
    }
};
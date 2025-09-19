// Number of occurrence

class Solution {
  public:
    int firstOccurrence(vector<int> &arr, int target){
        int n = arr.size();
        int s=0;
        int e=n-1;
        int ans=-1;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==target){
                ans = mid;
                e = mid-1;
            }
            else if(target > arr[mid]) s=mid+1;
            else e=mid-1;
        }
        
        return ans;
    }
    
    int lastOccurrence(vector<int> &arr, int target){
        int n = arr.size();
        int s=0;
        int e=n-1;
        int ans=-1;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==target){
                ans = mid;
                s = mid+1;
            }
            else if(target > arr[mid]) s=mid+1;
            else e=mid-1;
        }
        
        return ans;
    }
  
  
    int countFreq(vector<int>& arr, int target) {
        int start = firstOccurrence(arr, target);
        int end = lastOccurrence(arr, target);
        
        return (start!=-1) ? (end-start+1) : 0;
    }
};
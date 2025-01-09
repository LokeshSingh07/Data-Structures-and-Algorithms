// Missing in array -> GFG

class Solution {
  public:
    int missingNumber(vector<int>& arr){
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        for(int i=0; i<n; i++){
            int diff = abs(i - arr[i]);
            
            if(diff > 1) return i+1;
        }
        return n+1;
        
    }
};


// Missing and repeating -> GFG
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating=-1, missing=-1;
        
        
        // find repeating no.
        for(int i=0; i<n; i++){
            int idx = abs(arr[i])-1;    // 0 based indexing
            
            if(arr[idx] < 0){  // already visited
                repeating  = idx+1;
                continue;
            }
            
            arr[idx] *= -1;
        }
        
        // find missing no.
        for(int i=0; i<n; i++){
            if(arr[i] > 0){
                missing = i+1;
                break;
            }
        }
        
        return {repeating, missing};
    }
};
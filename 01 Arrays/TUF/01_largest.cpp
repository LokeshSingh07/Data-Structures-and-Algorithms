// Largest Element in Array

class Solution {
  public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++){
            if(arr[i] > maxi) maxi = arr[i];
        }
        return maxi;
    }
};
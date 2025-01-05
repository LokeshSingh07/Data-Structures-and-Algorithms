// Rotate Array by One

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        int temp = arr[n-1];
        
        for(int i=n-1; i>0; i--){
            arr[i] = arr[i-1];
        }
        arr[0]=temp;
    }
};
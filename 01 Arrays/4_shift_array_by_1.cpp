class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        int temp = arr[n-1];
        for(int i=n-1; i>0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
    }
};




// Rotate array by K    --  TLE 
class Solution {
public:
    void shiftBy1(vector<int> &nums){
        int n = nums.size();
        int temp = nums[n-1];
        for(int i=n-1; i>0; i--){
            nums[i] = nums[i-1];
        } 
        nums[0] = temp;
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        while(k--)
            shiftBy1(nums);
    }
};
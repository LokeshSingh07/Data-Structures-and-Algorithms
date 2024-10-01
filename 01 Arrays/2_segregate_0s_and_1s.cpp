class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int i=0;
        int j=arr.size()-1;
        
        while(i<j){
            if(arr[i] == 0){
                i++;
            }
            else{
                if(arr[j] == 0){
                    swap(arr[i++], arr[j--]);
                }
                else{
                    j--;
                }
            }
        }
    }
};



/*
    Approaches
    1. Sorting: Time complexity: O(n log n), Space complexity: O(1)
    2. Counting: Time complexity: O(n), Space complexity: O(1)
    3. Two Pointers: Time complexity: O(n), Space complexity: O(1)
*/
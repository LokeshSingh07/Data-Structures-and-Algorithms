// Second Largest


class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = -1;
        int secondLargest = -1;
        
        for(int i=0; i<n; i++){
            if(arr[i] > largest){
                secondLargest = largest;
                largest = arr[i];
            }
            else if((arr[i] > secondLargest) && (arr[i] != largest)){
                secondLargest = arr[i];
            } 
        }
        return secondLargest;
    }
};
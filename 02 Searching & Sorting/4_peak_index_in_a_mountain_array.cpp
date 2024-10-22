// 852. Peak Index in a Mountain Array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;

        while(s < e){
            int mid = s+(e-s)/2;
            if(arr[mid] < arr[mid+1]){      // A wali line
                s = mid+1;
            }
            else{                           // B wali line
                e = mid;
            }
        }
        
        return s;
    }
};


/*
    10 20 50 40 30 
    
            50
                40
                    30
        20
    10


*/
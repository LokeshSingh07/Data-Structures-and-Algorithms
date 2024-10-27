// In non sortedd array
#include<bits/stdc++.h>
using namespace std;


int BS(int arr[], int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s <= e){
        if(s==e) return s;

        if(mid & 1){
            if(mid-1 >= 0 && arr[mid] == arr[mid+1]) e = mid-1;
            else s=mid+1;
        }
        else{
            if(mid+1 < n && arr[mid] == arr[mid+1]) s = mid+2;
            else e=mid;                                 // catch --> ya to ans right me h ya to mai ans pr kadha hu
        }

        // update
        mid = s+(e-s)/2;
    }

    return -1;
}

int main(){
    int arr[] = {10,10,2,2,5,5,2,5,5,20,20,11,11,10,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = BS(arr, n);
    cout << "Index of first duplicate element is " << ans << endl;

return 0;
}




// ------------------------------------------------------------------------------------------

// 540. Single Element in a Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        int e=n-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(s==e || (mid > 0 && mid < n-1 && nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])) return nums[mid];

            if(mid %2 == 0){
                if(mid < n-1 && nums[mid] == nums[mid+1]) s=mid+2;
                else if(mid > 0 && nums[mid] == nums[mid-1]) e = mid-2;
            }
            else{
                if(mid < n-1 && nums[mid] == nums[mid+1]) e=mid-1;
                else if(mid > 0 && nums[mid] == nums[mid-1]) s = mid+1;
            }
        }

        return -1;
    }
};
#include<iostream>
using namespace std;


int missingElement(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid;
    int ans = -1;

    while(s <= e){
        mid = s+(e-s)/2;
        if((arr[mid] - mid) == 1){      // right me jao
            s = mid+1;
        }
        else{                           // ans store kro aur left me jao
            ans = mid;
            e = mid-1;
        }
    }
    if(ans == -1) ans = n;
    return ans+1;
}


int main(){
    int arr[] = {1,2,3,4,5,6,8};
    int n = sizeof(arr)/sizeof(int);
    int target = 9;

    int val = missingElement(arr, n);
    cout << "Missing element is : " << val << endl;



return 0;
}
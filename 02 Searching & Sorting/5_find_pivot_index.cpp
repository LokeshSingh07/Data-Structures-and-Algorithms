#include<iostream>
using namespace std;



int pivotIndex(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    while(s<=e){
        if(s==e) return s;

        // handle pivot separately 
        if(arr[mid] > arr[mid+1]){           // catch(Array out of bound) => (mid+1 < n), (mid-1 >= 0)
            return mid;
        }
        else if(arr[mid] < arr[mid-1]){
            return mid-1;
        }
        else if(arr[s] > arr[mid]){         // check for partition whether the mid is above or below the line
            e = mid-1;
        }
        else{                               // (arr[s] < arr[mid])
            s = mid+1;
        }

        // mid update
        mid = s+(e-s)/2;
    }

    return -1;
}


int main(){
    int arr[] = {12,14,16,2,4,6,8,10};
    int n = sizeof(arr)/sizeof(int);

    int ans = pivotIndex(arr, n);
    cout<<ans;

}
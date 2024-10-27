#include<iostream>
using namespace std;



int searchNearlySorted(int *arr, int n, int target){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s <= e){
        if(arr[mid] == target) return mid;
        if(mid < n-1 && arr[mid+1] == target) return mid+1;
        if(mid > 0 && arr[mid-1] == target) return mid-1;

        if(arr[mid] < target) s = mid+2;
        else e = mid-2;

        // update
        mid = s+(e-s)/2;
    }

    return -1;
}


int main(){
    int arr[]=  {20,10,30,50,40,70,60};
    int n = sizeof(arr)/sizeof(int);
    int target = 20;

    int indx = searchNearlySorted(arr, n, target);
    if(indx != -1)
        cout<<"Element is present a index : "<<indx<<endl;
    else
        cout<<"Element is not present in array"<<endl;



return 0;
}

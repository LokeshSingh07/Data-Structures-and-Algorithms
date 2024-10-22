#include<iostream>
using namespace std;


int binary_search(int *arr, int n, int targ){
    int s = 0;
    int e = n-1;

    int mid = s+(e-s)/2;
    while(s <= e){
        if(arr[mid] == targ) return mid;
        else if(arr[mid] < targ) s = mid+1;
        else e = mid-1;

        // catch
        mid = s+(e-s)/2;
    }
    return -1;
}


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    int target = 9;

    int index = binary_search(arr, n, target);
    if(index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "target not found" << endl;



return 0;
}
// first occurrence of element in sorted array
// last occurrence of element in SA
// Total occurrence of element in SA
#include<iostream>
using namespace std;


int findFirstOcc(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid] == target){
            ans = mid;
            e = mid-1;
        }
        else if(arr[mid] < target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }

    return ans;
}

int findLastOcc(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    int ans = -1;

    while(s <= e){
        int mid = s+(e-s)/2;
        if(arr[mid] == target){
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid] < target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

int findTotalOcc(int arr[], int n, int target){
    int first = findFirstOcc(arr, n, target);
    int last = findLastOcc(arr, n, target);
    return (last - first + 1);
}


int main(){
    int arr[] = {10,20,30,30,30,30,30,50,60};
    int n = sizeof(arr)/sizeof(int);
    int target = 30;

    int firstIdx = findFirstOcc(arr, n, target);
    if(firstIdx == -1){
        cout<<"Element not found in the array"<<endl;
    }
    else{
        cout << "First occurrence of element in SA: " << firstIdx << endl;
    }


    int lastIdx = findLastOcc(arr, n, target);
    if(lastIdx == -1){
        cout<<"Element not found in the array"<<endl;
    }
    else{
        cout << "First occurrence of element in SA: " << lastIdx << endl;
    }

    int totalOcc = findTotalOcc(arr, n, target);
    cout << "Total occurrences of element in SA: " << totalOcc << endl;



return 0;
}
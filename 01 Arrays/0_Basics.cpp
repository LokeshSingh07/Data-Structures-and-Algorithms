#include<iostream>
#include<limits.h>
using namespace std;


bool linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target) return true;
    }
    return false;
}

void countZeroOne(int arr[], int n){
    int zeroCnt=0, oneCnt=0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) zeroCnt++;
        else oneCnt++;
    }

    cout << "Zero count: " << zeroCnt << endl;
    cout << "One count: " << oneCnt << endl;
}

int minimumElement(int arr[], int n){
    int mini = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] < mini)
            mini = arr[i];
    }
    return mini;
}

int maximumElement(int arr[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}

void reverse(int arr[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        swap(arr[s++], arr[e--]);
    }
}

void extremePrint(int *arr, int n){
    int i=0;
    int j = n-1;

    while(i<j){
        cout<<arr[i]<<" "<<arr[j]<<" ";
        i++; j--;
        if(i==j) cout<<arr[i];
    }
}


int main(){
    int arr[] = {22,35,47,35,63,72,45,11,41};
    int size = sizeof(arr)/sizeof(int);
    int target = 11;

    bool ans = linearSearch(arr, size, target);
    if(ans) cout << "Element is present in array" << endl;
    else cout << "Element is not present in array" << endl;


    
    int arr2[] = {0,0,0,1,1,1,0,1,0,1,1,0,0,1};
    int n = sizeof(arr)/sizeof(int);

    countZeroOne(arr, n);

    cout<<"MINI : "<<minimumElement(arr, size)<<endl;
    cout<<"MAXI : "<<maximumElement(arr, size)<<endl;



    int arr3[] = {2,4,6,8,9};
    int n3 = sizeof(arr3)/sizeof(int);
    reverse(arr3, n3);
    cout<<"Reverse is : ";
    for(int i=0; i<n3; i++)
        cout<<arr3[i]<<" ";
    cout<<endl;




    // int arr4[] = {1,2,3,4,5,6};
    int arr4[] = {1,2,3,4,5,6,7};
    int n4 = sizeof(arr4)/sizeof(int);
    cout<<"Extreme Print is: ";
    extremePrint(arr4, n4);


return 0;
}
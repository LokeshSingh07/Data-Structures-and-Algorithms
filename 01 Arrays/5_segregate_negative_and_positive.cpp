#include<iostream>
using namespace std;


void segregate(int arr[], int n){
    int j=0;     // This index will track the position for negative(-ve) elements
    for(int index=0; index<n; index++){
        if(arr[index] < 0){
            swap(arr[index], arr[j]);
            j++;
        }
    }
}



int main(){
    int arr[] = {23,-7,12,-10,-11,40,60};
    int n = sizeof(arr)/sizeof(int);


    segregate(arr, n);

    cout<<"Printing the array : "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }




return 0;
}



/*
    Approaches
    1. Sorting:
    2. one pointer for tracking -ve and orther for traversing (index)

*/
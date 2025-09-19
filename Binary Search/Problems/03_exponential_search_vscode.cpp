// Exponential search
#include<iostream>
#include<vector>
using namespace std;




int BS(vector<int> &nums, int s, int e, int key){
    while(s<=e){
        int mid = s+(e-s)/2;
        if(nums[mid] == key) return mid;
        else if(nums[mid] > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}


int exponentialSearch(vector<int> &nums, int n, int key){
    if(nums[0] == key) return 0;

    int i=1;
    while(i<n && nums[i] <= key){
        i *= 2;
    }

    return BS(nums, i/2, min(i, n-1), key);
}




int main(){
    vector<int> nums = {3,4,5,8,11,23,45,67,87,89,91,95};
    int n = sizeof(nums);

    int key = 89;
    int index = exponentialSearch(nums, n, key);
    
    if(index != -1) cout<<"Element found at index : "<<index<<endl;
    else cout<<"Element not found"<<endl;





return 0;
}
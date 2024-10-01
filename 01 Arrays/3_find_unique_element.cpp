/*
    Given an array of elements occurring in multiples of k, except one element which doesn't occur in multiple of k. Return the unique element.

    Input: k = 3, arr[] = [6, 2, 5, 2, 2, 6, 6]
    Output: 5
    Explanation: Every element appears 3 times except 5.
*/ 
class Solution {
  public:
    int findUnique(int k, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        
        for(auto it: mp){
            if(it.second == 1) return it.first;
        }
    }
};




// Every element occur two times, except one element
#include<bits/stdc++.h>
using namespace std;

int findUnique(int arr[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}


int main(){
    int arr[] = {2,10,22,10,33,4,33,4,2};
    int n = 9;
    cout<<findUnique(arr, n);
return 0;
}


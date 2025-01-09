// Wave Array
#include<iostream>
#include<vector>
using namespace std;

void wavePrint(vector<vector<int>> vec){
    int m = vec.size();
    int n = vec[0].size();

    for(int j=0; j<n; j++){
        if(!(j&1)){   // even
            for(int i=0; i<m; i++){
                cout<<vec[i][j]<<" ";
            }
        }
        else{
            for(int i=m-1; i>=0; i--){
                cout<<vec[i][j]<<" ";
            }
        }
    }
}


int main(){
    vector<vector<int>> vec = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };


    wavePrint(vec);

return 0;
}
#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int> arr(5, 101);
    
    cout<<"\nPrinting vector : "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<endl;


    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);


    cout<<"Size of vector : "<<v.size();              // 5 --> kitne store h
    cout<<"\nCapacity of vector : "<<v.capacity();    // 8 --> kitne store kr skta h
    cout<<"\nIs vector empty : "<<v.empty();          // 0


    vector<int> b;
    cout<<"\nSize of vector : "<<b.size()<<endl;
    


    // 2D array
    // vector<vector<int>> vec;
    vector<vector<int>> vec(5, vector<int>(10, -1));

    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec[i].size(); j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }


    // Jagged array
    vector<vector<int>> jag(5);
    
    vector<int> v1(2, 0);
    vector<int> v2(5, 0);
    vector<int> v3(7, 0);
    vector<int> v4(3, 0);
    vector<int> v5(8, 0);

    jag.push_back(v1);
    jag.push_back(v2);
    jag.push_back(v3);
    jag.push_back(v4);
    jag.push_back(v5);

    for(int i=0; i<jag.size(); i++){
        for(int j=0; j<jag[i].size(); j++){
            cout<<jag[i][j]<<" ";
        }
        cout<<endl;
    }



return 0;
}
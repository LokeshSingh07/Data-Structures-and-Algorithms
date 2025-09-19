#include<iostream>
#include<limits.h>
using namespace std;


// Row wise print
void printArray(int arr[][3], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Column wise print
void colWisePrintArray(int arr[][3], int row, int col){
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}


// searching in matrix
bool findTarget(int arr[][3], int row, int col, int target){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == target) return 1;
        }
    }

    return 0;
}

// maximum element in matrix
void maxElement(int arr[][3], int row, int col){
    int maxi = INT_MIN;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] > maxi) maxi = arr[i][j];
        }
    }   
    cout<<maxi<<endl;
}

// minimum element in matrix
void minElement(int arr[][3], int row, int col){
    int mini = INT_MAX;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] < mini) mini = arr[i][j];
        }
    }   
    cout<<mini<<endl;
}

// Row wise sum in matrix
void rowWiseSum(int arr[][4], int row, int col){
    for(int i=0; i<row; i++){
        int sum = 0;
        for(int j=0; j<col; j++){
            sum += arr[i][j];
        }
        cout<<"Sum of "<<i+1<<"th row : "<<sum<<endl;
    }
}

// Col wise sum in matrix
void colWiseSum(int arr[][4], int row, int col){
    for(int i=0; i<col; i++){
        int sum = 0;
        for(int j=0; j<row; j++){
            sum += arr[j][i];
        }
        cout<<"Sum of "<<i+1<<"th col : "<<sum<<endl;
    }
}

// Diagonal sum in matrix
void diagonalSum(int arr[][4], int row, int col){
    int sum = 0;
    for(int i=0; i<row; i++){
        sum += arr[i][i];
    }
    cout<<"\nSum of diagonal elements : "<<sum<<endl;
}

// Transpose of a matrix
void transpose(int arr[][3], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<=i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}





int main(){
    // Initializing 2d array
    int arr[3][3] = {
        {32, 62, 13},
        {52, 46, 8},
        {9,11, 12}
    };

    // Address = C*i + j
    int barr[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 40, 11, 12},
        {9, 40, 11, 12},
    };
    int r=4; int c=4;


    cout<<"Row wise print:\n";
    printArray(arr, 3, 3);
    
    cout<<"\nCol wise print:\n";
    colWisePrintArray(arr, 3, 3);




    bool isPresent = findTarget(arr, 3, 3, 12);
    if(isPresent) cout<<"\nPresent";
    else cout<<"\nNot Present";




    cout<<"\nPrinting maximum number : ";
    maxElement(arr, 3, 3);
    cout<<"\nPrinting minimum number : ";
    minElement(arr, 3, 3);




    cout<<"\nSum of each row : "<<endl;
    rowWiseSum(barr, r, c);

    cout<<"\nSum of each column : "<<endl;
    colWiseSum(barr, r, c);

    diagonalSum(barr, r, c);
        



    cout<<"\nBefore transpose "<<endl;
    printArray(arr, 3, 3);

    transpose(arr, 3, 3);
    
    cout<<"\nAfter transpose "<<endl;
    printArray(arr, 3, 3);






return 0;
}
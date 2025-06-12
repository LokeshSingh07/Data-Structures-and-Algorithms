// Merge Sort

class Solution {
  public:
    void merge(vector<int> &arr, int s, int mid, int e){
        int n1 = mid-s+1;
        int n2 = e-mid;
        
        // copy the value
        vector<int> left(n1,0), right(n2,0);
        for(int i=0; i<n1; i++){
            left[i] = arr[s+i];
        }
        for(int j=0; j<n2; j++){
            right[j] = arr[mid+1+j];
        }
        
        // two pointer
        int i=0, j=0, k=s;
        while(i<n1 && j<n2){
            if(left[i] < right[j]){
                arr[k++] = left[i++];
            }else{
                arr[k++] = right[j++];
            }
        }
        
        while(i<n1){
            arr[k++] = left[i++];
        }
        while(j<n2){
            arr[k++] = right[j++];
        }
        
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r) return;
        
        int mid = l+(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};
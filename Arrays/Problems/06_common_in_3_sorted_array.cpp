// Common in 3 Sorted Arrays

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3){
        int m=arr1.size(), n=arr2.size(), p=arr3.size();
        int i=0, j=0, k=0;
        vector<int> ans;
            
        while(i<m && j<n && k<p){
            if((arr1[i] == arr2[j]) && (arr2[j] == arr3[k])){
                if(ans.empty() || ans.back() != arr1[i]) ans.push_back(arr1[i]);
                i++, j++, k++;
            }
            else if(arr1[i] < arr2[j]) i++;
            else if(arr2[j] < arr3[k]) j++;
            else k++;
        }
        
        return ans;
    }
};
// Union of 2 Sorted with Duplicates

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        int l1=a.size();
        int l2=b.size();
        int i=0, j=0;
        
        while(i<l1 && j<l2){
            if(a[i] == b[j]){
                // check for duplicate
                if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i] < b[j]){
                // check for duplicate
                if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
                i++;
            }
            else{
                 // check for duplicate
                if(ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
                j++;
            }
        }
        
        // check if a[] is empty, if not move all ele from a[] to ans
        while(i<l1){ 
            // check for duplicate
            if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
            i++;
        }
        // check if b[] is empty, if not move all ele from b[] to ans
        while(j<l2){
             // check for duplicate
            if(ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
            j++;
        }
        
        return ans;
    }
};
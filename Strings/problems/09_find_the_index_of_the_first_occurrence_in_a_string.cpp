// 28. Find the Index of the First Occurrence in a String

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i=0, j=0, k=0;

        while(k<m && j<n){
            if(haystack[j] != needle[k]){
                k=0;
                i++;
                j=i;
            }
            else{
                k++;
                j++;
            }
        }

        return k == m ? i : -1;
    }
};
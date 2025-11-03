// Longest Subarray with Sum K

// Approach-1: Using map
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int sum=0, len=0;
        unordered_map<int,int> mp;        // {sum, index}
        mp[0] = -1;
        
        for(int j=0; j<n; j++){
            sum += arr[j];
            
            if(mp.find(sum-k) != mp.end()){
                len = max(len, j - mp[sum-k]);
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = j;
            }
        }
        
        
        return len;
    }
};



// Approach-1: same code
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<long, int> mp;        // store { prefixSum, index }
        int maxLen = 0;
        int sum = 0;
        
        for(int j=0; j<n; j++){
            sum += arr[j];
            if(sum == k){
                maxLen = max(maxLen, j+1);
            }
            
            // find rem, is it present in map
            int rem = sum - k;
            if(mp.find(rem) != mp.end()){
                maxLen = max(maxLen, j-mp[rem]);
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = j;
            }
        }
        return maxLen;
        
    }
};
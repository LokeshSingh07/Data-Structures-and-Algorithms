// Longest Subarray with Sum K

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
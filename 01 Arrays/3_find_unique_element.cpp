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
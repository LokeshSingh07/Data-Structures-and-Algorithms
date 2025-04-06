// 2391. Minimum Amount of Time to Collect Garbage

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        unordered_map<char, int> mp;
        int total = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            for(char c: garbage[i]){
                count++;
                mp[c] = i;
            }
        }


        string Options = "MPG";
        total += count;
        for(char c: Options){
            for(int j=1; j<=mp[c]; j++){
                total += travel[j-1];
            }
        }

        return total;
    }
};
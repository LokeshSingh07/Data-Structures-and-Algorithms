// First Repeating Element

// Method 1: Brute Force  --> TLE
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i]==arr[j]) return i+1;
            }
        }
        
        return -1;
    }
};


// Method 2: Using Hashing
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
            
        // store it in map
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        // iterate over map
        for(int i=0; i<n; i++){
            if(mp[arr[i]] > 1) return i+1;
        }
        return -1;
    }
};
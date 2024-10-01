// 1207. Unique Number of Occurrences [https://leetcode.com/problems/unique-number-of-occurrences/]

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto it: arr){
            mp[it]++;
        }

        unordered_set<int> st;
        for(auto it: mp){
            if(st.find(it.second) != st.end()){
                return false;
            }
            st.insert(it.second);
        }

        return true;
    }
};



/*
    Approaches
    1. Brute Force: Iterate through the array and for each element, check if it
    occurs the same number of times in the array. This approach has a time complexity
    of O(n^2) where n is the number of elements in the array.

    2. Hashing: Use a hash map to store the frequency of each element in the
    array. Then, iterate through the hash map and check if the frequency of each
    element is unique. This approach has a time complexity of O(n) where n is the
    number of elements in the array.

    3. Sorting: Sort the array and then iterate through it to check if the
    frequency of each element is unique. This approach has a time complexity of
    O(n log n) where n is the number of elements in the array.
*/
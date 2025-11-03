// 435. Non-overlapping Intervals

struct comp{
    bool operator()(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals), comp());
    
        int removeCount = 0;
        vector<int> prev = intervals[0];
        for(int i=1; i<n; i++){
            if(intervals[i][0] < prev[1]){
                removeCount++;
                
            }
            else prev = intervals[i];
        }
        
        return removeCount;
    }
};
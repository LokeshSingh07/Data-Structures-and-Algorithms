// Meeting Rooms


/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals), [](auto &x, auto &y){
            return x.start < y.start;
        });

        for(int i=1; i<n; i++){
            if(intervals[i].start < intervals[i-1].end) return false;
        }

        return true;
    }
};

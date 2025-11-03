// Meeting Rooms II


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
    static bool comparator(Interval &x, Interval &y){
        return x.start < y.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(begin(intervals), end(intervals), comparator);
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &interval : intervals){
            if(!pq.empty() && interval.start >= pq.top()) pq.pop();
            pq.push(interval.end);
        }

        return pq.size();
    }
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    static bool myComp(const Interval& i1, const Interval& i2) {
        return i1.start < i2.start;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int N = intervals.size();
        if (N < 2) return true;
        sort(intervals.begin(), intervals.end(), myComp);
        for (int i = 1; i < N; i++) {
            if (intervals[i].start < intervals[i - 1].end) return false;
        }
        return true;
    }
};
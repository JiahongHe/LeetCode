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
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int N = intervals.size();
        if (N == 0) return 0;
        vector<int> Start(N, 0);
        vector<int> End(N, 0);
        for (int i = 0; i < N; i++) {
            Start[i] = intervals[i].start;
            End[i] = intervals[i].end;
        }
        sort(Start.begin(), Start.end());
        sort(End.begin(), End.end());
        int counter = 0;
        int endIndex = 0;
        for (int i = 0; i < N; i++) {
            if (Start[i] < End[endIndex]) counter++;
            else endIndex++;
        }
        return counter;
    }
};
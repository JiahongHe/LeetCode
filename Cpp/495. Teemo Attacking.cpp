class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0;
        int N = timeSeries.size();
        if (N == 0 || duration == 0) return result;
        for (int i = 0; i < N - 1; i++) {
            if (i < N - 1) {
                if (timeSeries[i+1] - timeSeries[i] <= duration) {
                    result += timeSeries[i+1] - timeSeries[i];
                } else {
                    result += duration;
                }
            }
        }
        result += duration;
        return result;
    }
};
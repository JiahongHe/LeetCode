class Solution {
public:
    int hIndex(vector<int>& citations) {
    int N = citations.size();
        if (N == 0) return 0;
        int left = 0, right = N - 1, mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            int count = N - mid;
            if (count == citations[mid]) return N - mid;
            else if (count < citations[mid]) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return N - left;
    }
};
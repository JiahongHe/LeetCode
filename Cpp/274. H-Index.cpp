class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        if (N == 0) return 0;
        vector<int> bucket (N + 1, 0);
        for (int n : citations) {
            if (n > N) bucket[N] += 1;
            else bucket[n] += 1;
        }
        int hInd = 0;
        int count = 0;
        for (int i = N; i > -1; i--) {
            count += bucket[i];
            if (count >= i) return i;
        }
        return 0;
    }
};
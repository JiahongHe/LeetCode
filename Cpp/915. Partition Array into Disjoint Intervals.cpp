class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int N = A.size();
        if (N == 0) return 0;
        vector<int> largest (N, INT_MIN);
        vector<int> smallest (N, INT_MAX);
        largest[0] = A[0];
        smallest[N-1] = A[N-1];
        for (int i = 1; i < N; i++) {
            smallest[N-1-i] = A[N-1-i] < smallest[N-i] ? A[N-1-i] : smallest[N-i];
            largest[i] = A[i] > largest[i-1] ? A[i] : largest[i-1];
        }
        for (int i = 0; i < N; i++) {
            if (largest[i] <= smallest[i+1]) return i + 1;
        }
        return -1;
    }
};
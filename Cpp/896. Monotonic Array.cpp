class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int N = A.size();
        bool isDecreasing = true;
        bool isIncreasing = true;
        for (int i = 0; i < N - 1; i++) {
            if (!(isIncreasing || isDecreasing)) break;
            if (A[i] < A[i + 1]) isIncreasing = false;
            if (A[i] > A[i + 1]) isDecreasing = false;
        }
        return isIncreasing || isDecreasing;
    }
};
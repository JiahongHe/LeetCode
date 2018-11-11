class Solution {
public:
    string minWindow(string S, string T) {
        int N = S.size(), M = T.size();
        if (N == 0 || M == 0) return "";
        int indexS = 0, indexT = 0, minStart = 0, minLength = INT_MAX;
        while (indexS < N - M + 1) {
            indexT = 0;
            if (S[indexS] == T[indexT]) {
                cout << indexS << endl;
                indexT++;
                int end = indexS + 1;
                while (indexT < M) {
                    if (end > N) {
                        return minLength == INT_MAX ? "" : S.substr(minStart, minLength);
                    }
                    if (S[end] == T[indexT]) indexT++;
                    end++;
                }
                if (end - indexS < minLength) {
                    minLength = end - (minStart = indexS);
                }
            }
            indexS++;
        }
        return minLength == INT_MAX ? "" : S.substr(minStart, minLength);
    }
};
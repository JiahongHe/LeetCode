class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> dp (N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) dp[i][i] = 1;
        
        for (int dis = 1; dis < N; dis++) {
            for (int i = 0; i < N - dis; i++) {
                int j = i + dis;
                if (s[i] == s[j]) {
                    if (dis == 1) {
                        dp[i][j] = 2;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        /*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */
        return dp[0][N - 1];
    }
};
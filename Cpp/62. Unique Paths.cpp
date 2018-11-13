class Solution {
    int helper(int m, int n, int r, int c, vector<vector<int>>& dp) {
        if (r >= m || c >= n) return 0;
        if (dp[r][c] > -1) return dp[r][c];
        int result = 0;
        result += helper(m, n, r + 1, c, dp);
        result += helper(m, n, r, c + 1, dp);
        dp[r][c] = result;
        return result;
    }
public:
    int uniquePaths(int m, int n) {
        int result = 0;
        if (m <= 0 || n <= 0) return 0;
        vector<vector<int>> dp (m, vector<int>(n, -1));
        dp[m-1][n-1] = 1;
        return helper(m, n, 0, 0, dp);
    }
};
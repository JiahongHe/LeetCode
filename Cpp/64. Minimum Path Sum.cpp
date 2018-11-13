class Solution {
    int helper(vector<vector<int>>& grid, int N, int M, vector<vector<int>>& dp, int r, int c) {
        if (r >= N || c >= M) return INT_MAX;
        if (dp[r][c] > -1) return dp[r][c];
        int down = helper(grid, N, M, dp, r + 1, c);
        int right = helper(grid, N, M, dp, r, c + 1);
        int result = grid[r][c] + min(down, right);
        dp[r][c] = result;
        return result;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int N = grid.size();
        if (N == 0) return 0;
        int M = grid[0].size();
        if (M == 0) return 0;
        vector<vector<int>> dp (N, vector<int> (M, -1));
        dp[N-1][M-1] = grid[N-1][M-1];
        return helper(grid, N, M, dp, 0, 0);
    }
};
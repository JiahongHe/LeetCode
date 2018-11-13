class Solution {
    int helper(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int r, int c, int N, int M) {
        if (r >= N || c >= M || obstacleGrid[r][c] == 1) return 0;
        if (dp[r][c] != -1) return dp[r][c];
        int result = 0;
        result += helper(obstacleGrid, dp, r + 1, c, N, M);
        result += helper(obstacleGrid, dp, r, c + 1, N, M);
        dp[r][c] = result;
        return result;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int N = obstacleGrid.size();
        if (N == 0) return 0;
        int M = obstacleGrid[0].size();
        if (M == 0) return 0;
        vector<vector<int>> dp (N, vector<int>(M, -1));
        dp[N-1][M-1] = 1;
        int result = helper(obstacleGrid, dp, 0, 0, N, M);
        return result;
    }
};
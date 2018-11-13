class Solution {
    int minimumPath(vector<vector<int>>& triangle, vector<vector<int>>& dp, int h, int c) {
        if (h >= triangle.size() || c >= h+1) return 0;
        if (dp[h][c] != -1) return dp[h][c];
        int left = minimumPath(triangle, dp, h+1, c);
        int right = minimumPath(triangle, dp, h+1, c+1);
        dp[h][c] = triangle[h][c] + min(left, right);
        return dp[h][c];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int H = triangle.size();
        vector<vector<int>> dp;
        for (int i = 0; i < H; i++) {
            dp.push_back(vector<int>(i+1, -1));
        }
        for (int i = 0; i < triangle[H-1].size(); i++) {
            dp[H-1][i] = triangle[H-1][i];
        }
        return minimumPath(triangle, dp, 0, 0);
    }
};
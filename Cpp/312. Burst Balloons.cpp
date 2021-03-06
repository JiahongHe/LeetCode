class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp (N + 2, vector<int> (N + 2, 0));
        for (int l = 1; l < N + 1; l++) {
            for (int i = 1; i <= N - l + 1; i++) {
                int j = l + i - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][N];
    }
};
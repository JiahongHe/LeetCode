class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        if (N == 0 || amount == 0) return 0;
        int maxCount = amount + 1;
        vector<int> dp (amount + 1, maxCount);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < N; j++) {
                dp[i] = min(dp[i], i >= coins[j] ? dp[i - coins[j]] + 1 : INT_MAX);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if (N == 0) return 0;
        vector<int> dp (N, 0);
        for (int i = 1; i < N; i++) {
            dp[i] = max(prices[i] - prices[i - 1], 0) + dp[i - 1];
        }
        return dp[N - 1];
    }
};
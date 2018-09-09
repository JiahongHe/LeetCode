class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if (N == 0) return 0;
        int maxPro = 0;
        int buyPrice = prices[0];
        for (int i = 1; i < N; i++) {
            if (prices[i] > buyPrice) {
                maxPro += (prices[i] - buyPrice);
                buyPrice = INT_MAX;
            }
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            }
        }
        return maxPro;
    }
};
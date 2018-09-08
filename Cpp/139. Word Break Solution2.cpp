class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict (wordDict.begin(), wordDict.end());
        int N = s.size();
        if (N < 1) return false;
        vector<bool> dp (N + 1, false);
        dp[0] = true;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < N + 1; j++) {
                if (dp[i] && dict.count(s.substr(i, j - i))) dp[j] = true;
            }
        }
        return dp[N];
    }
};
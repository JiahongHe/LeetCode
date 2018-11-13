class Solution {
    void comboSum(int k, int n, vector<vector<int>>& result, vector<int>& combo) {
        if (combo.size() == k && n == 0) {
            result.push_back(combo);
            return;
        } else if (combo.size() < k) {
            for (int i = combo.empty() ? 1 : combo.back() + 1; i <= 9; i++) {
                combo.push_back(i);
                comboSum(k, n - i, result, combo);
                combo.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k <= 0 || n < 3) return result;
        vector<int> combo;
        comboSum(k, n, result, combo);
        return result;
    }
};
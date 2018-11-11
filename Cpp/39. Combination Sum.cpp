class Solution {
    void comboSum(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combo, int N, int start) {
        if (target == 0) {
            result.push_back(combo);
            return;
        }
        for (int i = start; i < N && target >= 0; i++) {
            combo.push_back(candidates[i]);
            comboSum(candidates, target - candidates[i], result, combo, N, i);
            combo.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int N = candidates.size();
        if (N == 0) return result;
        sort(candidates.begin(), candidates.end());
        vector<int> combo;
        comboSum(candidates, target, result, combo, N, 0);
        return result;
    }
};
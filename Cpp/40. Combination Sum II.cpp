class Solution {
    void comboSum(vector<int>& candidates, int target, set<vector<int>>& result_set, vector<int>& combo, int start) {
        if (target == 0) {
            result_set.insert(combo);
            return;
        } else {
            for (int i = start; i < candidates.size() && target >= 0; i++) {
                combo.push_back(candidates[i]);
                comboSum(candidates, target - candidates[i], result_set, combo, i + 1);
                combo.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.size() == 0) return result;
        set<vector<int>> result_set;
        vector<int> combo;
        sort(candidates.begin(), candidates.end());
        comboSum(candidates, target, result_set, combo, 0);
        for (auto it = result_set.begin(); it != result_set.end(); it++) {
            result.push_back(*it);
        }
        return result;
    }
};
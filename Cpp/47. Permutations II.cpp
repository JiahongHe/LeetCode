class Solution {
    void permute(set<vector<int>>& resultSet, int left, int right, vector<int>& nums) {
        if (left == right) {
            resultSet.insert(nums);
            return;
        }
        for (int i = left; i <= right; i++) {
            swap(nums[left], nums[i]);
            permute(resultSet, left + 1, right, nums);
            swap(nums[left], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return vector<vector<int>>();
        set<vector<int>> resultSet;
        permute(resultSet, 0, N - 1, nums);
        vector<vector<int>> result (resultSet.begin(), resultSet.end());
        return result;
    }
};
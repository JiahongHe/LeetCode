class Solution {
    int comboSum(vector<int>& nums, int target, vector<int>& dp) {
        if (dp[target] > -1) return dp[target];
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                result += comboSum(nums, target - nums[i], dp);
            }
        dp[target] = result;
        }
        return result;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0 || target <= 0) return 0;
        vector<int> dp (target + 1, -1);
        dp[0] = 1;
        int result = comboSum(nums, target, dp);
        return result;
    }
};
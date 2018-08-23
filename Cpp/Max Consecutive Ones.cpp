class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int curr_ones = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                max_ones = max(max_ones, curr_ones);
                curr_ones = 0;
                continue;
            }
            curr_ones++;
        }
        if (curr_ones != 0) {
            max_ones = max(max_ones, curr_ones);
        }
        return max_ones;
    }
};
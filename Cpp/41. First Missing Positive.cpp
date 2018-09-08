class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        if (N < 1) return 1;
        for (int i = 0; i < N; i++) {
            while (nums[nums[i] - 1] != nums[i] && nums[i] > 0 && nums[i] < N) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < N; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return N + 1;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        if (N < 3) return 0;
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[N - 1];
        for (int i = 0; i < N - 2; i++) {
            int start = i + 1;
            int end = N - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target) return sum;
                if (sum < target) start++;
                if (sum > target) end--;
                if (abs(sum - target) < abs(result - target)) {
                    result = sum;
                }
            }
        }
        return result;
    }
};
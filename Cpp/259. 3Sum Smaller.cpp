class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int N = nums.size();
        if (N < 3) return 0;
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N - 2; i++) {
            int start = i + 1;
            int end = N - 1;
            while (start < end && start > i) {
                int curSum = nums[i] + nums[start] + nums[end];
                if (curSum >= target) {
                    end--;
                }
                else {
                    count += (end - start);
                    start++;
                }
            }
        }
        return count;
    }
};
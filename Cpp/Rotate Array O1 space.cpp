class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        if (N == 0) return;
        k = k % N;
        for (int j = 0; j < k; j++) {
            int tmp = nums[N - 1];
            for (int i = 1; i < N; i++) {
                nums[N - i] = nums[N - 1 - i];
            }
            nums[0] = tmp;
        }
    }
};
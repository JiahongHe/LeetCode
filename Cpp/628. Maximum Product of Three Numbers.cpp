class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int prod1 = nums[0] * nums[1] * nums[N - 1];
        int prod2 = nums[N - 1] * nums[N - 2] * nums[N - 3];
        return max(prod1, prod2);
    }
};
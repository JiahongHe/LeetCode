class Solution {
    int maxNumber(vector<int>& nums, int start, int k) {
        int maxNum = INT_MIN;
        for (int i = 0; i < k; i++) {
            maxNum = max(maxNum, nums[start + i]);
        }
        return maxNum;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int N = nums.size();
        if (N < k || N == 0) return result;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            result.push_back(maxNumber(nums, i, k));
        }
        return result;
    }
};
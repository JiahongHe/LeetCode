class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s == NULL || nums.size() == 0) {
            return 0;
        }
        int start = 0;
        int sum = 0;
        int min_length = nums.size() + 1;
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            while (sum >= s) {
                min_length = min(min_length, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        if (min_length > nums.size()) {
            return 0;
        }
        return min_length;
    }
};
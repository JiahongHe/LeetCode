class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int N = nums.size();
        if (N < 3) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = N - 1; i > 1; i--) {
            int start = 0;
            int end = i - 1;
            while (start < end) {
                if (nums[i] < nums[start] + nums[end]) {
                    count += (end - start);
                    end--;
                }
                else {
                    start++;
                }
            }
        }
        return count;
    }
};
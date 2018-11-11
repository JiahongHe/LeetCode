class Solution {
    void nextPermutation(string& nums) {
        int N = nums.size(), k, l;
        for (k = N - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) break;
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (l = N - 1; l > k; l--) {
            if (nums[l] > nums[k]) break;
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
public:
    string getPermutation(int n, int k) {
        if (n == 0) return "";
        string s = "";
        for (int i = 0; i < n; i++) s += to_string(i + 1);
        for (int i = 1; i < k; i++) {
            nextPermutation(s);
        }
        return s;
    }
};
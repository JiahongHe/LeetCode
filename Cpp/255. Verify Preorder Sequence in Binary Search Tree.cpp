class Solution {
    bool isValid(vector<int>& nums, int low, int high) {
        if (low >= high) return true;
        int rootVal = nums[low];
        int i = low + 1;
        for (; i <= high; i++) {
            if (nums[i] > rootVal) break;
        }
        int j = i;
        for (; j <= high; j++) {
            if (nums[j] < rootVal) return false;
        }
        bool leftValid = isValid(nums, low + 1, i - 1);
        bool rightValid = isValid(nums, i, high);
        return leftValid && rightValid;
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        int N = preorder.size();
        if (N == 0) return true;
        return isValid(preorder, 0, N - 1);
    }
};
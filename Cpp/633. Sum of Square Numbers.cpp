class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = pow(c, 0.5);
        while (left <= right) {
            int sum = left * left + right * right;
            if (sum == c) return true;
            if (sum < c) left++;
            else right--;
        }
        return false;
    }
};
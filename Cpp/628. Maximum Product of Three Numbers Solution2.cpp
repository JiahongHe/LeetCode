class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int N = nums.size();
        int maxPos1 = INT_MIN, maxPos2 = INT_MIN, maxPos3 = INT_MIN;
        int minNeg1 = INT_MAX, minNeg2 = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (nums[i] > maxPos1) {
                maxPos3 = maxPos2;
                maxPos2 = maxPos1;
                maxPos1 = nums[i];
            }
            else if (nums[i] > maxPos2) {
                maxPos3 = maxPos2;
                maxPos2 = nums[i];
            }
            else if (nums[i] > maxPos3) maxPos3 = nums[i];
            if (nums[i] < minNeg1) {
                minNeg2 = minNeg1;
                minNeg1 = nums[i];
            }
            else if (nums[i] < minNeg2) minNeg2 = nums[i];
        }
        return max(maxPos1 * maxPos2 * maxPos3, maxPos1 * minNeg1 * minNeg2);
    }
};
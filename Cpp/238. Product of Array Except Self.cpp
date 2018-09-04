class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCounter = 0;
        int indexFirstZero = -1;
        int N = nums.size();
        vector<int> result (N, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (zeroCounter == 0) {
                    indexFirstZero = i;
                }
                zeroCounter ++;
                continue;
            }
            product = product * nums[i];
        }
        if (zeroCounter > 1) return result;
        if (zeroCounter == 1) {
            result[indexFirstZero] = product;
            return result;
        }
        for (int i = 0; i < nums.size(); i++) {
            result[i] = product / nums[i];
        }
        return result;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        if (N == 1) return nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];
        int res = nums[0];
        for (int i = 1; i < N; i++) {
            int tmpMaxProd = max(max(maxProd * nums[i], minProd * nums[i]), nums[i]);
            int tmpMinProd = min(min(maxProd * nums[i], minProd * nums[i]), nums[i]);
            maxProd = tmpMaxProd;
            minProd = tmpMinProd;
            res = max(maxProd, res);
        }
        return res;
    }
};
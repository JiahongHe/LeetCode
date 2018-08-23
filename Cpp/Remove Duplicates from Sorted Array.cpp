class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        }
        int curr_num = nums[0];
        int k = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (curr_num != nums[i]) {
                curr_num = nums[i];
                k++;
                nums[k] = nums[i];
                continue;
            }
        }
        return k + 1;
    }
};
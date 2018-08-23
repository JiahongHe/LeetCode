class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        k = k % nums.size();
        for (int i = nums.size() - k; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size() - k; i++) {
            tmp.push_back(nums[i]);
        }
        nums = tmp;
    }
};

/* using iterator
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        k = k % nums.size();
        int len = nums.size();
        if (k > 0) {
            tmp.insert(tmp.end(), nums.end() - k, nums.end());
            nums.insert(nums.begin(), tmp.begin(), tmp.end());
            nums.assign(nums.begin(), nums.begin() + len);
        }
    }
};
*/

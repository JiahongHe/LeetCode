class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            while (nums[nums[i] - 1] != nums[i] && nums[i] > 0 && nums[i] <= N) 
                swap(nums[nums[i] - 1], nums[i]); 
        }
        for (int i = 0; i < N; i++) {
            //cout << nums[i] << " ";
            if (nums[i] != i + 1)
                result.push_back(nums[i]);
        } 
        return result;
    }
};
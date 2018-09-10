class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        for (int num : nums) {
            if (num == INT_MIN) {
                lower = num + 1;
                continue;
            }
            if (lower < num - 1) 
                result.push_back(to_string(lower) + "->" + to_string(num - 1));
            else if (lower == num - 1) 
                result.push_back(to_string(lower));
            
            if (num == INT_MAX) 
                return result;
            
            lower = num + 1;
        }
        
        if (lower < upper) 
            result.push_back(to_string(lower) + "->" + to_string(upper));
        else if (lower  == upper) 
            result.push_back(to_string(lower));
        return result;
    }
};
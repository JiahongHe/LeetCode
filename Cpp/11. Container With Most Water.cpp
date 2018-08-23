class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }
        int i = 0;
        int j = height.size() - 1;
        int max_val = 0;
        while (i < j) {
            int curr = (j - i) * min(height[i], height[j]);
            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
            max_val = max(max_val, curr);
        }
        return max_val;
    }
};
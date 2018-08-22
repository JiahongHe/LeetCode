class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        int ind = 0;
        int left = 0;
        int low = 0;
        int right = n;
        int high = m;
        while (left <= right && low <= right) {
            switch (ind % 4) {
                case 0:
                    right--;
                    for (int i = left; i < right; i++) {
                        res.push_back(matrix[low][i]);
                    }
                    left++;
                    ind++;
                    break;
                case 1:
                    high--;
                    for (int i = low; i < high; i ++) {
                        res.push_back(matrix[i][right + 1]);
                    }
                    low++;
                    ind++;
                    break;
                case 2:
                    for (int i = right + 1; i > left; i--) {
                        res.push_back(matrix[high + 1][i]);
                    }
                    ind++;
                    break;
                case 3:
                    for (int i = high + 1; i > low; i--) {
                        res.push_back(matrix[i][low]);
                    }
                    ind++;
                    break;
                default:
                    break;
            } 
        }
        return res;
    }
};
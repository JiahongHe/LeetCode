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
        int right = n - 1;
        int high = m - 1;
        while (left <= right && low <= high) {
            cout << left << " " << right << " , " << low << " " << high << endl;
            if (left == right) {
                for (int i = low; i <= high; i++) {
                    res.push_back(matrix[i][right]); 
                }
                break;
            }
            if (low == high) {
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[low][i]);
                }
                break;
            }
            switch (ind % 4) {
                case 0:
                    for (int i = left; i < right; i++) {
                        res.push_back(matrix[low][i]);
                    }
                    break;
                case 1:
                    for (int i = low; i < high; i ++) {
                        res.push_back(matrix[i][right]);
                    }
                    break;
                case 2:
                    for (int i = right; i > left; i--) {
                        res.push_back(matrix[high][i]);
                    }
                    break;
                case 3:
                    for (int i = high; i > low; i--) {
                        res.push_back(matrix[i][low]);
                    }
                    low++;
                    left++;
                    right--;
                    high--;
                    break;
                default:
                    break;
            }
            ind++;
        }
        return res;
    }
};
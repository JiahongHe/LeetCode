class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        for (int i = 0; i < m + n - 1; i++) {
            if (i % 2 == 0) {
                for (int j = i; j > -1; j--) {
                    if ((j < m) && (i - j) < n) {
                        int num = matrix[j][i - j];
                        res.push_back(num);
                    }
                }
            }
            else {
                for (int j = 0; j < i + 1; j++) {
                    if ((j < m) && (i - j) < n) {
                        int num = matrix[j][i - j];
                        res.push_back(num);
                    }
                }
            }
        }
        return res;
    }
};
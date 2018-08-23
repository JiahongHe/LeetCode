class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows < 1) {
            return {};
        }
        vector<int> last_row = {1};
        vector<vector<int>> result = {{1}};
        for (int i = 1; i < numRows; i++) {
            vector<int> new_row = {1};
            for (int j = 1; j < i; j++) {
                new_row.push_back(last_row[j - 1] + last_row[j]);
            }
            new_row.push_back(1);
            result.push_back(new_row);
            last_row = new_row;
        }
        return result;
    }
};
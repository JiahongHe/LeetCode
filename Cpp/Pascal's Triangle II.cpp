class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return {};
        }
        vector<int> last_row = {1};
        for (int i = 0; i < rowIndex; i++) {
            vector<int> new_row = {};
            new_row.push_back(1);
            cout << endl;
            cout << i << endl;
            for (int j = 1; j < i + 1; j++) {
                new_row.push_back(last_row[j - 1] + last_row[j]);
            }
            new_row.push_back(1);
            for (int i = 0; i < new_row.size(); i++) {
                cout << new_row[i] << " ";
            }
            last_row = new_row;
        }
        return last_row;
    }
};
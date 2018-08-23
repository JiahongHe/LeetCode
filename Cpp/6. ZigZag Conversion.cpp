class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() <= numRows || numRows == 1) {
            return s;
        }
        vector<string> vec = vector<string>(numRows, "");
        int step = 1;
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            vec[index] += s[i];
            if (index == 0) {
                step = 1;
            }
            else if (index == numRows - 1) {
                step = -1;
            }
            index += step;
        }
        string result = "";
        for (int i = 0; i < vec.size(); i++) {
            result += vec[i];
        }
        return result;
    }
};
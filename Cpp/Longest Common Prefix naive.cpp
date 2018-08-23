class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string pre = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = ' ';
            for (int j = 0; j < strs.size(); j++) {
                if ((i > strs[j].size() - 1)) {
                    cout << i << endl;
                    return pre;
                }
                if (c == ' ') {
                    c = strs[j][i];
                    continue;
                }
                if (c != strs[j][i]) {
                    cout << "boo" << endl;
                    return pre;
                }
                cout << c << endl;
            }
            pre += c;
        }
        return pre;
    }
};
class Solution {
    public:
    int myAtoi(string str) {
        vector<string> tokens;
        string token = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ' ') {
                token += str[i];
            }
            else {
                if (token.size() > 0) {
                    tokens.push_back(token);
                    token = "";
                }
            }
        }
        if (token.size() > 0) {
            tokens.push_back(token);
        }
        string token_num = "";
        for (auto token: tokens) {
            bool flag = true;
            for (char c: token) {
                if (!((c >= '0' && c <= '9') || c == '-')) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                token_num = token;
                break;
            }
        }
        int p = token_num.size() - 1;
        int sign = 1;
        int res = 0;
        for (int i = 0; i < token_num.size(); i++) {
            if (token_num[i] == '-') {
                sign = -1;
                continue;
            }
            res += (int)(token_num[i] - '0') * pow(10, p - i);
            cout << res << endl;
        }
        res = res * sign;
        return res;
    }
};
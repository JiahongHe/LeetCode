class Solution {
    void generate(vector<string>& result, string curStr, int n, int curLeft, int curRight) {
        if (curRight == n) {
            result.push_back(curStr);
            return;
        }
        if (curLeft > n) return;
        generate(result, curStr + '(', n, curLeft + 1, curRight);
        if (curLeft > curRight) generate(result, curStr + ')', n, curLeft, curRight + 1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n < 1) return result;
        generate(result, "", n, 0, 0);
        return result;
    }
};
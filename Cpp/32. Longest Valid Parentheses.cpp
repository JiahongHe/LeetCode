class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.size();
        if (N == 0) return 0;
        stack<int> indices;
        indices.push(-1);
        int result = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') 
                indices.push(i);
            if (s[i] == ')') {
                indices.pop();
                if (!indices.empty()) {
                    int topInd = indices.top();
                    result = max(result, i - topInd);
                }
                else indices.push(i);
            }
        }
        return result;
    }
};
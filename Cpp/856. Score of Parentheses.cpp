class Solution {
    int curIndex = 0;
public:
    int scoreOfParentheses(string S) {
        int score = 0;
        while (curIndex < S.size()) {
            char c = S[curIndex++];
            if (c == '(') {
                if (S[curIndex] == ')') {
                    score++;
                    curIndex++;
                }
                else score += 2 * scoreOfParentheses(S);
            }
            else return score;
        }
        return score;
    }
};
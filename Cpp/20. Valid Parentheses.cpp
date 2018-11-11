class Solution {
public:
    bool isValid(string s) {
        int N = s.size();
        if (N == 0) return true;
        unordered_map<char, char> parentheses = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stack;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
                stack.push(s[i]);
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (stack.empty() || parentheses.at(s[i]) != stack.top()) return false;
                else stack.pop();
            }
        }
        return stack.empty();
    }
};
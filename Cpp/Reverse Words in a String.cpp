class Solution {
public:
    void reverseWords(string &s) {
        vector<string> tokens;
        string token = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && token.size() > 0) {
                tokens.push_back(token);
                token = "";
                continue;
            }
            if (s[i] != ' ') {
                token += s[i];
            }
        }
        if (token.size() > 0) {
            tokens.push_back(token);
        }
        for (int i = 0; i < tokens.size(); i++) {
        }
        cout << endl;
        s = "";
        if (tokens.size() == 0) {
            return;
        }
        for (int i = tokens.size() - 1; i > 0; i--) {
            s += tokens[i] + " "; 
        }
        s += tokens[0];
    }
};
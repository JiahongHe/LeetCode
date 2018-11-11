class Solution {
    void trimString(string& s) {
        int firstNonSpace = 0;
        int lastNonSpace = s.size() - 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') firstNonSpace++;
            else break;
        }
        for (int i = s.size() - 1; i > -1; i--) {
            if (s[i] == ' ') lastNonSpace--;
            else break;
        }
        s = s.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
    }
public:
    bool isNumber(string s) {
        trimString(s);
        int N = s.size();
        if (!isdigit(s[N - 1]) && s[N - 1] != '.') return false;
        cout << s << endl;
        if (N == 0) return false;
        bool hasNumber = false;
        bool hasNumberAfterExpo = false;
        bool hasExponent = false;
        bool hasDeciPoint = false;
        for (int i = 0; i < N; i++) {
            if (isdigit(s[i])) {
                hasNumber = true;
                if (hasExponent) hasNumberAfterExpo = true;
            }
            else if (s[i] == '.') {
                if (hasDeciPoint || hasExponent) return false;
                else hasDeciPoint = true;
            }
            else if (s[i] == 'e') {
                if (hasExponent || !hasNumber) return false;
                else hasExponent = true;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (i != 0 && !(s[i - 1] == 'e')) return false;
            }
            else return false;
        }
        if (hasExponent && !hasNumberAfterExpo) return false;
        if (!hasNumber) return false;
        return true;
    }
};
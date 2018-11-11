class Solution {
    string getStr(string S) {
        string res = "";
        for (char c : S) {
            if (c != '-') res += toupper(c);
        }
        return res;
    }
public:
    string licenseKeyFormatting(string S, int K) {
        string str = getStr(S);
        int N = str.size();
        if (N == 0) return "";
        int numBlock = N / K;
        int firstBlock = N % K;
        string res = str.substr(0, firstBlock);
        for (int i = 0; i < numBlock; i++) {
            res += ("-" + str.substr(i * K + firstBlock, K));
        }
        if (firstBlock == 0) res = res.substr(1);
        return res;
    }
};
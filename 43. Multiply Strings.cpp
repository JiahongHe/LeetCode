class Solution {
    string multiplyByChar(string s, char c) {
        int N = s.size();
        string result = s;
        int carry = 0;
        int numc = c - '0';
            for (int i = N - 1; i > -1; i--) {
            int nums = s[i] - '0';
            int multi = nums * numc + carry;
            result[i] = (multi % 10) + '0';
            carry = multi / 10;
        }
        char cc = carry + '0';
        if (carry > 0) result = cc + result;
        return result;
    }
    string strAdd(string s1, string s2) {
        int N1 = s1.size();
        int N2 = s2.size();
        int carry = 0;
        string result = s1;
        if (N1 < N2) return strAdd(s2, s1);
        for (int i = 0; i < N1; i++) {
            int n1 = s1[N1 - i - 1] - '0';
            int n2 = i > N2 - 1? 0 : s2[N2 - i - 1] - '0';
            int summ = n1 + n2 + carry;
            result[N1 - i - 1] = (summ % 10) + '0';
            carry = summ / 10;
        }
        if (carry > 0) result = '1' + result;
        return result;
    }
public:
    string multiply(string num1, string num2) {
        int N1 = num1.size();
        int N2 = num2.size();
        if (N1 == 0 || N2 == 0) return "";
        string result = "";
        for (int i = N2 - 1; i > -1; i--) {
            char c = num2[i];
            string curProduct = multiplyByChar(num1, c);
            string padding = "";
            for (int j = 0; j < N2 - 1 - i; j++) padding += '0';
            result = strAdd(curProduct + padding, result);
        }
        if (result[0] == '0') return "0";
        return result;
    }
};
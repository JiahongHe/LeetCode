class Solution {
public:
    long binToDec(string s) {
        long p = s.size() - 1;
        long res = 0;
        for (char c: s) {
            res += (c - '0') * pow(2, p);
            p--;
        }
        return res;
    }
    string decToBin(long n) {
        string res = "";
        if (n == 0) {
            return "0";
        }
        while (n > 0) {
            char c = n % 2 + '0';
            res = c + res;
            n = n - (n % 2);
            n /= 2;
        }
        return res;
    }
    string addBinary(string a, string b) {
        long num_a = binToDec(a);
        long num_b = binToDec(b);
        long num_res = num_a + num_b;
        return decToBin(num_res);
    }
};
class Solution {
public:
    void addZeros(string& s, int n) {
        for (int i = 0; i < n; i++) {
            s = '0' + s;
        }
    }
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            addZeros(a, b.size() - a.size());
        }
        if (a.size() > b.size()) {
            addZeros(b, a.size() - b.size());
        }
        map<char, int> nums{{'1', 1}, {'0', 0}};
        map<int, char> chars{{1, '1'}, {0, '0'}};
        int carry = 0;
        string res;
        cout << a << " " << b << endl;
        for (int i = a.size() - 1; i > -1; i--) {
            int val = nums[a[i]] + nums[b[i]] + carry;
            int num = val % 2;
            carry = val / 2;
            res = chars[num] + res;
        }
        cout << res << endl;
        if (carry == 1) {
            res = '1' + res;
        }
        return res;
    }
};
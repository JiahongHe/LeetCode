class Solution {
public:
    string reverseString(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};
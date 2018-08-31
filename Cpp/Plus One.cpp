class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int N = digits.size();
        vector<int> result = digits;
        if (N == 0) return result;
        int carry = 1;
        for (int i = N - 1; i > -1; i--) {
            if (carry == 0) break;
            carry = 0;
            int added = digits[i] + 1;
            if (added > 9) {
                added -= 10;
                carry = 1;
            }
            result[i] = added;
        }
        if (carry == 1) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};
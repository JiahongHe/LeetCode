class Solution {
    pair<int, int> parseCoefficients(string s) {
        int sign1 = 1, sign2 = 1;
        int start1 = 0, start2 = 1;
        if (!isdigit(s[0])) {
            sign1 = s[0] == '-' ? -1 : 1;
            start1 = 1;
        }
        int index = s.find('+', 1);
        int coe1 = stoi(s.substr(start1, index));
        if (!isdigit(s[index + start2])) {
            if (s[index + start2] == '-') sign2 = -1;
            start2++;
        }
        int coe2 = stoi(s.substr(index + start2));
        return make_pair(coe1 * sign1, coe2 * sign2);
    }
public:
    string complexNumberMultiply(string a, string b) {
        pair<int, int> coe_a = parseCoefficients(a);
        pair<int, int> coe_b = parseCoefficients(b);
        int result_coe1 = coe_a.first * coe_b.first - coe_a.second * coe_b.second;
        int result_coe2 = coe_a.first * coe_b.second + coe_a.second * coe_b.first;
        return to_string(result_coe1) + '+' + to_string(result_coe2) + 'i';
    }
};
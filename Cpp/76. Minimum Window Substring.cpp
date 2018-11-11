class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map (128, 0);
        for (char c : t) map[c]++;
        int counter = t.size(), start = 0, end = 0, minStart = 0, minLength = INT_MAX;
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) counter--;
            while (counter == 0) {
                if (end - start < minLength) minLength = end - (minStart = start);
                if (map[s[start++]]++ == 0) counter++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};
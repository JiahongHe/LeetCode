using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> seen;
        int count = 0;
        int longest = 0;
        for (int i = 0; i < s.length(); i++) {
            if (seen.find(s[i]) != seen.end()) {
                count = min(i - seen.at(s[i]), count + 1);
            }
            else {
                count += 1;
            }
            seen[s[i]] = i;
            longest = max(longest, count);
        }
        return longest;
    }
};
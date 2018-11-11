class Solution {
public:
    int longestPalindrome(string s) {
        int N = s.size();
        if (N == 0) return 0;
        unordered_map<char, int> charCount;
        for (char c : s) {
            if (charCount.find(c) != charCount.end()) charCount.at(c) += 1;
            else charCount.insert(make_pair(c, 1));
        }
        int maxLength = 0;
        bool oddEncountered = false;
        for (auto it = charCount.begin(); it != charCount.end(); it++) {
            if (it->second % 2 == 0) maxLength += it->second;
            else {
                oddEncountered =true;
                maxLength += it->second - 1;
            }
        }
        if (oddEncountered) maxLength++;
        return maxLength;
    }
};
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int N = s.size();
        if (N == 0) return true;
        unordered_map<char, int> counter;
        for (char c : s) {
            if (counter.find(c) != counter.end()) counter.at(c) += 1;
            else counter.insert(make_pair(c, 1));
        }
        bool oddSeen = false;
        for (auto it = counter.begin(); it != counter.end(); it++) {
            if (it->second % 2 == 1) {
                if (oddSeen) return false;
                else oddSeen = true;
            }
        }
        return true;
    }
};
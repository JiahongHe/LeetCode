class Solution {
    unordered_map<string, bool> memo;
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict (wordDict.begin(), wordDict.end());
        return wordBreak(s, dict);
    }
    
    bool wordBreak(string s,  unordered_set<string> dict) {
        if (memo.find(s) != memo.end()) return memo[s];
        if (dict.find(s) != dict.end()) return memo[s] = true;
        for (int i = 1; i < s.size(); i++) {
            const string leftStr = s.substr(0, i);
            const string rightStr = s.substr(i);
            if (dict.count(rightStr) && wordBreak(leftStr, dict)) return memo[s] = true;
        }
        return memo[s] = false;
    }
};
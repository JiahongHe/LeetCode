class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> numbers = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        int N = digits.size();
        if (N < 1) return result;
        result.push_back("");
        for (int i = 0; i < N; i++) {
            int num = digits[i] - '0';
            if (num > 9 || num < 0) return result;
            string candidates = numbers[num];
            vector<string> cache;
            for (int j = 0; j < candidates.size(); j ++) {
                for (int k = 0; k < result.size(); k++) {
                    cache.push_back(result[k] + candidates[j]);
                }
            }
            result = cache;
        }
        return result;
    }
};
class Solution {
    bool charCountCMP(vector<int>& charCount1, vector<int>& charCount2) {
        int M = charCount1.size(), N = charCount2.size();
        if (M != N) return false;
        for (int i = 0; i < M; i++) {
            if (charCount1[i] != charCount2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int N = s2.size(), k = s1.size();
        if (N == 0 || N < k) return false;
        vector<int> charCount2 (128, 0);
        vector<int> charCount1 (128, 0);
        
        for (char c : s1) charCount1[c] += 1;
        for (int i = 0; i < k; i++) charCount2[s2[i]] += 1;
        
        if (charCountCMP(charCount1, charCount2)) return true;
        for (int i = k; i < N; i++) {
            charCount2[s2[i - k]] -= 1;
            charCount2[s2[i]] += 1;
            if (charCountCMP(charCount1, charCount2)) return true;
        }
        return false;
    }
};
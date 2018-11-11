class Solution {
    bool isAnagram(vector<int>& count1, vector<int>& count2) {
        int N = count1.size(), M = count2.size();
        if (N != M) return false;
        for (int i = 0; i < N; i++) {
            if (count1[i] != count2[i]) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int N = s.size(), k = p.size();
        if (N < k || N == 0) return result;
        vector<int> charCountP (128, 0);
        vector<int> charCountS (128, 0);
        for (char c : p) charCountP[c] += 1;
        for (int i = 0; i < k; i++) charCountS[s[i]] += 1;
        if (isAnagram(charCountP, charCountS)) result.push_back(0);
        for (int i = k; i < N; i++) {
            charCountS[s[i - k]]--;
            charCountS[s[i]]++;
            if (isAnagram(charCountP, charCountS)) result.push_back(i - k + 1);
        }
        return result;
    }
};
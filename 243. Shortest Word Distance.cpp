class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int N = words.size();
        if (N == 0) return 0;
        int shortestDist = INT_MAX;
        int word1Ind = -1;
        int word2Ind = -1;
        for (int i = 0; i < N; i++) {
            if (words[i] == word1) word1Ind = i;
            if (words[i] == word2) word2Ind = i;
            if (word1Ind != -1 && word2Ind != -1) shortestDist = min(shortestDist, abs((word1Ind - word2Ind)));
        }
        return shortestDist;
    }
};
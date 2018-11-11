class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int N = words.size();
        if (N == 0) return false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (i >= words[j].size() || j >= N || words[i][j] != words[j][i]) {
                    return false;  
                }
            }
        }
        return true;
    }
};
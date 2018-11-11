class Solution {
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int N = s.size(), n = words.size();
        if (N == 0 || n == 0) return result;
        int m = words[0].size();
        unordered_map<string, int> wordCount;
        
        for (auto word : words) {
            if (wordCount.find(word) != wordCount.end()) wordCount.at(word) += 1;
            else wordCount[word] = 1;
        }
        
        for (int i = 0; i < N - n * m + 1; i++) {
            unordered_map<string, int> wordCountCopy (wordCount);
            int k = n;
            int j = i;
            while (k > 0) {
                string word = s.substr(j, m);
                if (wordCountCopy.find(word) == wordCountCopy.end() || wordCountCopy.at(word) < 1) break;
                wordCountCopy.at(word) -= 1;
                k--;
                j += m;
            }
            if (k == 0) result.push_back(i);
        }
        return result;
    }
};
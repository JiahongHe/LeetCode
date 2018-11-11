class Solution {
    bool search(vector<vector<char>>& board, int x, int y, int M, int N, string word, int index) {
        if (x < 0 || x > M - 1 || y < 0 || y > N - 1 || board[x][y] != word[index]) return false;
        if (index == word.size() - 1) return true;
        char cur = board[x][y];
        board[x][y] = 0;
        bool found = search(board, x + 1, y, M, N, word, index + 1)
                  || search(board, x - 1, y, M, N, word, index + 1)
                  || search(board, x, y + 1, M, N, word, index + 1) 
                  || search(board, x, y - 1, M, N, word, index + 1);
        board[x][y] = cur;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return false;
        int M = board.size();
        if (M == 0) return false;
        int N = board[0].size();
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == word[0]) {
                    if(search(board, i, j, M, N, word, 0)) return true;
                }
            }
        }
        return false;
    }
};
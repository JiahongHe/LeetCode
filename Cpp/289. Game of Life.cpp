class Solution {
    bool isAlive(const vector<vector<int>>& board, int x, int y) {
        if (x < 0 || y < 0 || x > board.size() - 1 || y > board[0].size() - 1) return false;
        return board[x][y] % 2 == 1;
    }
    int aliveNeighbors(const vector<vector<int>>& board, int x, int y) {
        int count = 0;
        if (isAlive(board, x - 1, y)) count++;
        if (isAlive(board, x + 1, y)) count++;
        if (isAlive(board, x - 1, y + 1)) count++;
        if (isAlive(board, x - 1, y - 1)) count++;
        if (isAlive(board, x, y + 1)) count++;
        if (isAlive(board, x, y - 1)) count++;
        if (isAlive(board, x + 1, y + 1)) count++;
        if (isAlive(board, x + 1, y - 1)) count++;
        return count;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int M = board.size();
        if (M < 1) return;
        int N = board[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int numAlive = aliveNeighbors(board, i, j);
                if (numAlive == 2 && board[i][j] == 1) board[i][j] = 3;
                if (numAlive == 3) board[i][j] = board[i][j] == 1 ? 3 : 2;
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
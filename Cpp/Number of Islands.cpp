class Solution {
public:
    void helper(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y, int M, int N) {
        if (x < 0 || x > M - 1 || y < 0 || y > N - 1 || grid[x][y] != '1' || visited[x][y] == 1) {
            return;
        }
        visited[x][y] = 1;
        helper(grid, visited, x + 1, y, M, N);
        helper(grid, visited, x - 1, y, M, N);
        helper(grid, visited, x, y + 1, M, N);
        helper(grid, visited, x, y - 1, M, N);
    }
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size();
        if (M == 0) {
            return 0;
        }
        int N = grid[0].size();
        int count = 0;
        vector<vector<int>> visited = vector<vector<int>>(M, vector<int>(N, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (visited[i][j] != 1 && grid[i][j] == '1') {
                    count++;
                    helper(grid, visited, i, j, M, N);
                }
            }
        }
        return count;
    }
};
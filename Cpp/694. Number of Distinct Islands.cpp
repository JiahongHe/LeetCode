class Solution {
    void DFS(vector<vector<int>>& grid, string direction, int x, int y, vector<vector<int>>& seen, int M, int N, string& islandMap) {
        if (x < 0 || x > M - 1 || y < 0 || y > N - 1 || seen[x][y] == 1 || grid[x][y] == 0) return;
        seen[x][y] = 1;
        islandMap += direction;
        DFS(grid, "n", x - 1, y, seen, M, N, islandMap);
        DFS(grid, "s", x + 1, y, seen, M, N, islandMap);
        DFS(grid, "w", x, y - 1, seen, M, N, islandMap);
        DFS(grid, "e", x, y + 1, seen, M, N, islandMap);
        islandMap += "b";
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int M = grid.size();
        if (M == 0) return 0;
        int N = grid[0].size();
        if (N == 0) return 0;
        vector<vector<int>> seen (M, vector<int> (N, 0));
        unordered_set<string>islands;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1 && seen[i][j] == 0) {
                    string islandMap = "";
                    DFS(grid, "S", i, j, seen, M, N, islandMap);
                    islands.insert(islandMap);
                }
            }
        }
        return islands.size();
    }
};
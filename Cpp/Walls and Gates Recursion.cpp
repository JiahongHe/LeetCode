class Solution {
public:
    void helper(vector<vector<int>>& rooms, int x, int y, int M, int N, int distance) {
        if (x < 0 || x >= M || y < 0 || y >= N || distance > rooms[x][y] || rooms[x][y] == -1) {
            return;
        }
        rooms[x][y] = distance;
        helper(rooms, x - 1, y, M, N, distance + 1);
        helper(rooms, x + 1, y, M, N, distance + 1);
        helper(rooms, x, y - 1, M, N, distance + 1);
        helper(rooms, x, y + 1, M, N, distance + 1);
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) {
                    helper(rooms, i, j, rooms.size(), rooms[0].size(), 0);
                }
            }
        }
    }
};
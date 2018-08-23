class Solution {
public:
    void availableRoutes(vector<vector<int>> rooms, vector<vector<int>> visited, queue<int, int> que, int m, int n) {
        int M = rooms.size();
        int N = rooms[0].size();
        if (m < M - 1 && rooms[m + 1][n] != -1 && visited[m + 1][n] != 1) {
            que.push({m + 1, n});
        }
        if (n < N - 1 && rooms[m][n + 1] != -1 && visited[m][n + 1] != 1) {
            que.push({m, n + 1});
        }
        if (m > 0 && rooms[m - 1][n] != -1 && visited[m - 1][n] != 1) {
            que.push({m - 1, n});
        }
        if (n > 0 && rooms[m][n - 1] != -1 && visited[m][n - 1] != 1) {
            que.push({m, n - 1});
        }
    }
    
    void BFS(vector<vector<int>>& rooms, int m, int n) {
        vector<vector<int>> visited = vector<vector<int>>(rooms.size(), vector<int>(rooms[0].size(), 0));
        visited[m][n] = 1;
        queue<int, int> que;
        availableRoutes(rooms, visited, que, m, n);
        int val = 0;
        while (que.size() > 0) {
            val++;
            queue<int, int> new_que;
            while (que.size() > 0) {
                auto new_point = queue.front();
                queue.pop();
                int x = new_point.first;
                int y = new_point.second;
                rooms[x][y] = min(rooms[x][y], val);
                visited[x][y] = 1;
                availableRoutes(rooms, visited, new_que, x, y);
            }
            que = new_que;
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<int, int> starts;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == 0) {
                    starts.push({i, j});
                }
            }
        }
        while (starts.size() > 0) {
            auto start = starts.front();
            starts.pop();
            BFS(rooms, start.first, start.second);
        }
    }
};
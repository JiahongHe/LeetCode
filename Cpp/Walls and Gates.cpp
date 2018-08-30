class Solution {
public:
    void availableRoutes(vector<vector<int>> rooms, vector<vector<int>> visited, deque<pair<int, int>>& que, int m, int n) {
        int M = (int)rooms.size();
        int N = (int)rooms[n].size();
        if (m < M - 1 && rooms[m + 1][n] != -1 && visited[m + 1][n] != 1) {
            que.push_back({m + 1, n});
        }
        if (n < N - 1 && rooms[m][n + 1] != -1 && visited[m][n + 1] != 1) {
            que.push_back({m, n + 1});
        }
        if (m > 0 && rooms[m - 1][n] != -1 && visited[m - 1][n] != 1) {
            que.push_back({m - 1, n});
        }
        if (n > 0 && rooms[m][n - 1] != -1 && visited[m][n - 1] != 1) {
            que.push_back({m, n - 1});
        }
    }
    
    void BFS(vector<vector<int>>& rooms, int m, int n) {
        vector<vector<int>> visited = vector<vector<int>>(rooms.size(), vector<int>(rooms[n].size(), 0));
        visited[m][n] = 1;
        deque<pair<int, int>> que;
        deque<pair<int, int>> new_que;
        availableRoutes(rooms, visited, que, m, n);
        int val = 0;
        while (que.size() > 0) {
            val++;
            new_que.clear();
            while (que.size() > 0) {
                auto new_point = que.front();
                que.pop_front();
                int x = new_point.first;
                int y = new_point.second;
                rooms[x][y] = min(rooms[x][y], val);
                visited[x][y] = 1;
                availableRoutes(rooms, visited, new_que, x, y);
            }
            que = new_que;
        }
        cout << endl;
        cout << "visited" << endl;
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < visited[0].size(); j++) {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        deque<pair<int, int>> starts;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == 0) {
                    starts.push_back({i, j});
                }
            }
        }
        while (starts.size() > 0) {
            auto start = starts.front();
            starts.pop_front();
            BFS(rooms, start.first, start.second);
        }
    }
};


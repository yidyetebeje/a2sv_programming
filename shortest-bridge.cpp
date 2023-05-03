class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        bool found = false;

        // Use DFS to identify the first island
        for (int i = 0; i < m && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                }
            }
        }

        // Use BFS to find the shortest path to the second island
        int steps = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dirs[k], ny = y + dirs[k+1];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 2) {
                        continue;
                    }
                    if (grid[nx][ny] == 1) {
                        return steps;
                    }
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            steps++;
        }

        return -1;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;
        q.push({i, j});
        dfs(grid, i-1, j, q);
        dfs(grid, i+1, j, q);
        dfs(grid, i, j-1, q);
        dfs(grid, i, j+1, q);
    }
};
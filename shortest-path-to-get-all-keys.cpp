class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int all_keys = 0;
        pair<int, int> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    start = {i, j};
                } else if (islower(grid[i][j])) {
                    all_keys |= (1 << (grid[i][j] - 'a'));
                }
            }
        }
        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<tuple<int, int, int>> q;
        set<tuple<int, int, int>> visited;
        q.push({start.first, start.second, 0});
        visited.insert({start.first, start.second, 0});
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = get<0>(q.front());
                int y = get<1>(q.front());
                int keys = get<2>(q.front());
                q.pop();
                if (keys == all_keys) {
                    return steps;
                }
                for (auto move : moves) {
                    int nx = x + move.first;
                    int ny = y + move.second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') {
                        continue;
                    }
                    int new_keys = keys;
                    char c = grid[nx][ny];
                    if (islower(c)) {
                        new_keys |= (1 << (c - 'a'));
                    } else if (isupper(c)) {
                        if (!(keys & (1 << (c - 'A')))) {
                            continue;
                        }
                    }
                    tuple<int, int, int> state = {nx, ny, new_keys};
                    if (visited.count(state)) {
                        continue;
                    }
                    q.push(state);
                    visited.insert(state);
                }
            }
            steps++;
        }

        return -1;  // Not all keys can be collected
    }
};
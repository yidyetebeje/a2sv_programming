class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;
        
        // Initialize distance to 0 for cells containing 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Breadth-first search
        while (!q.empty()) {
            int curr_i = q.front().first;
            int curr_j = q.front().second;
            q.pop();
            for (auto dir : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                int neighbor_i = curr_i + dir.first;
                int neighbor_j = curr_j + dir.second;
                if (neighbor_i >= 0 && neighbor_i < rows && neighbor_j >= 0 && neighbor_j < cols) {
                    int new_dist = dist[curr_i][curr_j] + 1;
                    if (new_dist < dist[neighbor_i][neighbor_j]) {
                        dist[neighbor_i][neighbor_j] = new_dist;
                        q.push({neighbor_i, neighbor_j});
                    }
                }
            }
        }
        
        return dist;
    }
};
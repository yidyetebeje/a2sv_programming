class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj_list, vector<bool>& visited, vector<bool>& has_apple) {
        visited[node] = true;
        int time = 0;
        for (int child : adj_list[node]) {
            if (!visited[child]) {
                int child_time = dfs(child, adj_list, visited, has_apple);
                if (child_time > 0 || has_apple[child] > 0) {
                    time += child_time;
                }
            }
        }
        if (node != 0 && (time > 0 || has_apple[node] > 0)) {
            time += 2;
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj_list(n);
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        unordered_set<int> copyOfHas(hasApple.begin(), hasApple.end());
        return dfs(0, adj_list, visited, hasApple);
    }
};
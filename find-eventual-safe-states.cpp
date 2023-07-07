class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) {
                adj[node].push_back(i);
                inDegree[i]++;
            }
        }
        for(auto x: inDegree){
            cout << x << " ";
        }
        deque<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push_back(i);
            }
        }
        vector<int> safe;
        while(!q.empty()){
            int top = q.front();
            safe.push_back(top);
            for(int i = 0; i < adj[top].size(); i++){
                inDegree[adj[top][i]]--;
                if(inDegree[adj[top][i]] == 0){
                    q.push_back(adj[top][i]);
                }
            }
            q.pop_front();
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& colors) {
        if (colors[node] != 0) {
            return colors[node] == 2;
        }
        colors[node] = 1;
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, colors)) {
                return false;
            }
        }
        colors[node] = 2;
        return true;
    }
};
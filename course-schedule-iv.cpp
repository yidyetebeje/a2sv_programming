class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int source, vector<vector<int>>& isReachable, int x, vector<int>& visited){
        auto neighs = adj[source];
        visited[source] = 1;
        for(auto neigh: neighs){
            isReachable[x][neigh] = 1;
            if(!visited[neigh])
                dfs(adj, neigh, isReachable,x, visited);
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for(auto preq: prerequisites){
            adj[preq[0]].push_back(preq[1]);
        }
        vector<vector<int>> isReachable(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            vector<int> visited(n);
            isReachable[i][i] = 1;
            dfs(adj, i, isReachable, i,visited);
        }
        vector<bool> res(queries.size());
        int i = 0;
        for(auto query: queries){
            res[i++] = isReachable[query[0]][query[1]] == 1 ? true: false;
        }
        return res;
    }
};
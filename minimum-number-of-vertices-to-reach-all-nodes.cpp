class Solution {
public:
    vector<int> visited;
    void dfs(unordered_map<int, vector<int>>&adjList, int source){
        auto neighbours = adjList[source];
        for(auto x: neighbours){
            if(visited[x] == false){
                visited[x] = true;
                dfs(adjList, x);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adjList;
        for(auto e: edges){
            adjList[e[0]].push_back(e[1]);
        }
        visited.resize(n);
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                dfs(adjList, i);
            }
        }
        vector<int> res;
        for(int i = 0; i < visited.size();i++){
            if(visited[i] == false) res.push_back(i);
        }
        return res;
    }
};
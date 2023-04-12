class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adjList, int source, vector<int>& colors){
        auto neighbours = adjList[source];
        for(auto neigh: neighbours){
            if(colors[neigh] == -1){
                colors[neigh] = 1 - colors[source];
                if(!dfs(adjList, neigh, colors)) return false;
            } else if(colors[neigh] == colors[source]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjList;
        for(auto dis: dislikes){
            adjList[dis[0]].push_back(dis[1]);
            adjList[dis[1]].push_back(dis[0]);
        }
        vector<int> colors(n + 1, -1);
        for(int i = 1; i <= n; i++){
            if(colors[i] == -1){
                if(!dfs(adjList, i, colors)) return false;
            }
        }
        return true;
    }
};
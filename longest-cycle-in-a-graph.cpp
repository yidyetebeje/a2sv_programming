class Solution {
public:
    int dfs_timer = 0;
    void dfs(int v, unordered_map<int, vector<int>> &adjList, vector<int>& time_in, vector<int>& color, int& len) {
        time_in[v] = dfs_timer++;
        color[v] = 1;
        for (int u : adjList[v]){
            if (color[u] == 0)
                dfs(u, adjList, time_in, color,len);
            else if(color[u] == 1){
                len = max(len, time_in[v] - time_in[u] + 1);
            }
        }
        color[v] = 2;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> time_in(n);
        vector<int> color(n);
        unordered_map<int, vector<int>> adjList;
        for(int i = 0; i < edges.size();i++){
            if(edges[i] != -1)
                adjList[i].push_back(edges[i]);
        }
        int len = -1;
        for(int i = 0; i < n; i++){
            if(color[i] == 0){
                dfs(i, adjList, time_in,color,len);
            }
        }
        return len;
    }
};
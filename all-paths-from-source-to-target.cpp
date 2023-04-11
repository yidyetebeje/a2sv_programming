class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int src, vector<vector<int>> &graph, vector<int> adj[], int n)
    {
        temp.push_back(src);

        if (src == n - 1)
            ans.push_back(temp);

        for (auto i : adj[src])
            dfs(i, graph, adj, n);

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
                adj[i].push_back(it);
        }
        dfs(0, graph, adj, n);

        return ans;
    }
};
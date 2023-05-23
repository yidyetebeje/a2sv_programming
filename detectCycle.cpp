public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(int node,int parent,vector<int>adj[],vector<int>&visited)
    {
        visited[node] = 1;
        for(auto adjacentnode : adj[node])
        {
            if(!visited[adjacentnode])
            {
               if( dfs(adjacentnode , node , adj , visited) ) return true;
            }
            else
            if(adjacentnode != parent)
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        // Code here
        vector<int>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,-1,adj,visited)) return true;
            }
        }
        return false;
    }
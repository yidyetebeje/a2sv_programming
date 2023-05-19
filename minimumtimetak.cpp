class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            unordered_map<int,vector<int>> adjList;
            vector<int> inDegree(n + 1);
            for(auto edge: edges){
                adjList[edge[0]].push_back(edge[1]);
                inDegree[edge[1]]++;
            }
            deque<int> dq;
            for(int i = 1; i <= n; i++){
                if(inDegree[i] == 0) dq.push_back(i);
            }
            int count = 0;
            vector<int> res(n);
            while(!dq.empty()){
                count++;
                int sz = dq.size();
                while(sz--){
                    int x = dq.front();
                    res[x - 1] = count;
                    dq.pop_front();
                    for(auto edge: adjList[x]){
                        inDegree[edge]--;
                        if(inDegree[edge] == 0) dq.push_back(edge);
                    }
                }
            }
            return res;
        }
};
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(n);
        for(auto node: edges){
            adjList[node[0]].push_back(node[1]); 
            inDegree[node[1]]++;
        }
        vector<bool> visited(n, false);
        deque<int> dq;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0) dq.push_back(i);
        }
        unordered_map<int,set<int>> res;
        int count = 0;
        while(!dq.empty()){
            int x = dq.front();
            dq.pop_front();
            visited[x] = true;
            for(auto node: adjList[x]){
                auto y = res[x];
                if(!visited[node]){
                    res[node].insert(y.begin(), y.end());
                    res[node].insert(x);
                    inDegree[node]--;
                    if(inDegree[node] == 0) dq.push_back(node);
                }
            }
        }
        vector<vector<int>> ans(n,vector<int>());
        for(auto [key,val]: res){
            for(auto v: val){
                ans[key].push_back(v);
            }
        }
        return ans;
    }
};
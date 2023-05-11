class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjList;
        for(auto adj: adjacentPairs){
            adjList[adj[0]].push_back(adj[1]);
            adjList[adj[1]].push_back(adj[0]);
        }
        int source = 0;
        for(auto v: adjList){
            if(v.second.size() == 1){
                source = v.first;
                break;
            }
        }
        unordered_set<int> visited;
        deque<int> dq;
        dq.push_back(source);
        vector<int> res;
        while(!dq.empty()){
            int x = dq.front();
            res.push_back(x);
            dq.pop_front();
            visited.insert(x);
            for(auto child: adjList[x]){
                if(!visited.count(child)){
                    dq.push_back(child);
                }
            }
        }
        return res;
    }
};
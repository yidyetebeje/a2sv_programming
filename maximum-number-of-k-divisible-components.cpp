class Solution {
public:

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<pair<int,int>>> adjList(n + 1);
        vector<int> inDegree(n + 1);
        if(n == 1){
            return 1;
        }
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1], values[i]});
            adjList[edges[i][1]].push_back({edges[i][0], values[i]});
            inDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
        }
        unordered_map<int,int> mp;
        deque<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 1){
                q.push_back(i);
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            auto tp = q.front();
            inDegree[tp]--;
            q.pop_front();
            int take = 0;
            for(auto neigh: adjList[tp]){
                inDegree[neigh.first]--;
                int val = values[tp];
                if( !take && val % k == 0){
                    ans++;
                    take = 1;
                    values[tp] = 0;
                } else {
                    values[neigh.first] += (val % k);
                  
                }
                if(inDegree[neigh.first] == 1){
                    q.push_back(neigh.first);
                }
            }
        } 
        return ans;
    }
};
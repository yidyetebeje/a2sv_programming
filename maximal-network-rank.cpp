class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, set<int>> adjList;
        for(auto v: roads){
            adjList[v[0]].insert(v[1]);
            adjList[v[1]].insert(v[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int count = adjList[i].size() + adjList[j].size();
                if(adjList[j].count(i)) count--;
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(n);
        unordered_map<int, int> res;
        for(auto node: richer){
            adjList[node[0]].push_back(node[1]); 
            inDegree[node[1]]++;
        }
        vector<bool> visited(n, false);
        deque<int> dq;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0) dq.push_back(i);
        }
        for(int i = 0; i < n; i++){
            res[i] = i;
        }
        int count = 0;
        while(!dq.empty()){
            int x = dq.front();
            dq.pop_front();
            count++;
            visited[x] = true;
            for(auto node: adjList[x]){
                if(!visited[node]){
                    inDegree[node]--;
                    if(quiet[node] > quiet[x]){
                        quiet[node] = min(quiet[node], quiet[x]);
                        res[node] = res[x];
                    }
                    if(inDegree[node] == 0) dq.push_back(node);
                }
            }
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(res.count(i)) ans[i] = res[i];
            else ans[i] = i;
        }
        return ans;
    }
};
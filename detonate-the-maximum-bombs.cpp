class Solution {
public:
    unordered_map<string, vector<string>> buildGraph(vector<vector<int>>& bombs){
        unordered_map<string, vector<string>> adjList;
        for(int i = 0; i < bombs.size();i++){
            auto bmb = bombs[i];
            auto str = to_string(bmb[0]) + " " + to_string(bmb[1]) + " " + to_string(i);
            for(int j = 0; j < bombs.size(); j++){
                if(i == j ) continue;
                auto bm = bombs[j];
                auto dist = sqrt((long long)(bm[0] - bmb[0])*(long long)(bm[0] - bmb[0]) + ((long long)bm[1] - bmb[1]) * (long long)(bm[1] - bmb[1]));
                  auto distStr = to_string(bm[0]) + " " + to_string(bm[1]) + " " + to_string(j);
                if(dist <= bmb[2]){
                    adjList[str].push_back(distStr);
                }
            }
        }
        return adjList;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        deque<string> dq;
        auto graph = buildGraph(bombs);
        int ans = 0;
        for(int i = 0; i < bombs.size(); i++){
            auto str = to_string(bombs[i][0]) + " " + to_string(bombs[i][1]) + " " + to_string(i);
            unordered_set<string> visited;
            dq.push_back(str);
            visited.insert(str);
            int count = 1;
            while(!dq.empty()){
                auto node = dq.front();
                dq.pop_front();
                auto adjList = graph[node];
                for(auto adj: adjList){
                    if(visited.find(adj) == visited.end()){
                        
                        dq.push_back(adj);
                        visited.insert(adj);
                        count++;
                    }
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
class Solution {
public:
    double bfs(string start, string end, unordered_map<string,unordered_map<string, double>>& adj){
        deque<pair<string,double>> dq;
        dq.push_back({start, 1});
        set<string> visited;
        visited.insert(start);
        while(!dq.empty()){
            auto pr = dq.front();
            dq.pop_front();
            for(auto neigh: adj[pr.first]){
                double weight = pr.second * neigh.second;
                if(neigh.first == end){
                    return weight;
                }
                if(!visited.count(neigh.first)){
                    visited.insert(neigh.first);
                    dq.push_back({neigh.first, weight});
                }
            }
        }   
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string, double>> adj(27);
        for(int i = 0; i < equations.size(); i++){
            adj[equations[i][0]][equations[i][1]] = values[i];
            adj[equations[i][1]][equations[i][0]] = (double)1/values[i];
        }
    
        vector<double> res;
        for(int i = 0; i < queries.size(); i++){
            double ans = bfs(queries[i][0], queries[i][1], adj);
            res.push_back(ans);
        }
        return res;
    }
};
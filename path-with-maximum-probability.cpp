class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& times, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dist(n + 1);
        vector<vector<pair<int,double>>> adjList(n + 1, vector<pair<int,double>>());
        for(int i = 0; i < times.size(); i++){
            adjList[times[i][0]].push_back({times[i][1], succProb[i]});
            adjList[times[i][1]].push_back({times[i][0], succProb[i]});
        }
        set<int> visited;
        for(int i = 0; i < n;i++){
            dist[i] = INT_MIN;
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});
        dist[0] = 0;
        while(!pq.empty()){
            auto ans = pq.top();
            pq.pop();
            if(visited.count(ans.second)){
                continue;
            }
            visited.insert(ans.second);
            for(auto v: adjList[ans.second]){
                double distance = (double)ans.first * (double)v.second;
        
                if(distance > dist[v.first]){
                    dist[v.first] = distance;
                    pq.push({distance, v.first});
                }
            }
        }
        
        double ans = dist[end_node];
        if(ans == INT_MIN){
            return 0;
        }
        return ans;
    }
};
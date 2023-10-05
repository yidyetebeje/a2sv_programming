class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1);
        vector<vector<pair<int,int>>> adjList(n + 1, vector<pair<int,int>>());
        for(int i = 0; i < times.size(); i++){
            adjList[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        set<int> visited;
        for(int i = 0; i < n;i++){
            dist[i+1] = INT_MAX;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto ans = pq.top();
            pq.pop();
            if(visited.count(ans.second)){
                continue;
            }
            visited.insert(ans.second);
            for(auto v: adjList[ans.second]){
                int distance = ans.first + v.second;
                if(distance < dist[v.first]){
                    dist[v.first] = distance;
                    pq.push({distance, v.first});
                }
            }
        }
        
        int ans = *max_element(dist.begin(), dist.end());
        for(auto v: dist){
            cout << v << endl;
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
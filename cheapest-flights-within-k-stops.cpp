class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(int i = 0; i < flights.size(); i++){
            adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>  pq;
        vector<int> distance(n + 1, INT_MAX);
        vector<bool> visited(n + 1);
        pq.push({-k, 0, src});
        while(!pq.empty()){
            int w, k, node;
            tie(k, w, node) = pq.top();
            k = -1 *k;
            pq.pop();
            
           
            for(auto [child, weight]: adjList[node]){
                int dist = w + weight;
                if(k >= 0 && dist < distance[child]){
                    distance[child] = dist;
                    pq.push({-1*(k - 1), dist, child});
                }
            }
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst] ;
    }
};
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);


void bfs(int node, unordered_map<int, vector<int>>& mp, vector<int> &visited, int &ans, vector<int>& weight){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans = min(ans, weight[curr]);
        for(auto it : mp[curr]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}
signed main(){
    fast;
    int n, m;
    cin >> n >> m;
    vector<int> weight(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> weight[i];
    }
    unordered_map<int, vector<int>> adjList;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> visited(n + 1, 0);
    long long res = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            int ans = INT_MAX;
            // bfs 
            bfs(i, adjList, visited, ans, weight);
            res += ans;
        }
    }
    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define PB push_back
#define MP make_pair
const ll mod = 1e9 + 7, N = 2e6 + 7, M = 2e6 + 7, INF = INT_MAX / 10;
bool dfs(unordered_map<int, vector<int>> &adj, vector<int> &color, int node, int c)
{
    color[node] = c;
    for (auto it : adj[node])
    {
        if (color[it] == c)
            return false;
        if (color[it] == 0 && !dfs(adj, color, it, -c))
            return false;
    }
    return true;
}
void solve(int v, int e)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(v + 1, 0);
    int a = dfs(adj, color, 1, 1);
    if (a)
        cout << "BICOLOURABLE." << endl;
    else
        cout << "NOT BICOLOURABLE." << endl;
}
signed main()
{
    fast;
    int a,b;
    while(cin >> a && cin >> b){
        solve(a,b);
    }
    return 0;
}
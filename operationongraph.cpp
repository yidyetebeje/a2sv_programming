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
void solve()
{
}
signed main()
{
    fast;
    int n;
    cin >> n;
    int m;
    cin >> m;
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        if(a == 1){
            int b, c;
            cin >> b >> c;
            adj[b].push_back(c);
            adj[c].push_back(b);
        }
        else{
            int b;
            cin >> b;
            auto v = adj[b];
            if (v.size() == 0)
                continue;
            for (auto i : v)
                cout << i << " ";
            cout << endl;
        }
    }
}
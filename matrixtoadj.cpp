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
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            if(a == 1)
                adj[i + 1].push_back(j + 1);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << adj[i].size() << " ";
        for(auto x: adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
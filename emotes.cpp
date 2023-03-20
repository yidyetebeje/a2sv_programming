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
    int n, m, k;
    cin >> n >> m >> k; 
    vector<int> v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 0, times;
    times = m / (k + 1);
    ans += (times * v[n - 2]);
    times = m - times;
    ans += (times * v[n - 1]);
    cout << ans << endl;
}
signed main()
{
    fast;
    solve();
    return 0;
}
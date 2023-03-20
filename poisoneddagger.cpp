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
bool good(int n, ll h, vector<ll> &v, ll m)
{
    unsigned long long damages = m;
    for (int i = 0; i < n - 1; ++i){
        ll diff = v[i + 1] - v[i];
        damages += min(m, diff);
    }
    return damages < h; 
}
void solve()
{
    ll n, h;
    cin >> n >> h;
    vector<ll> v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    ll l = 1, r = 1e18;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (!good(n, h, v, m))
            r = m - 1;
        else
            l = m + 1;
    }
    cout << r + 1  << '\n';
}
signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
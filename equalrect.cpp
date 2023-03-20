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
    int n;
    cin >> n;
    ll f = 4 * n;
    vector<ll> v(f);
    unordered_map<ll, int> mp;
    forn(i, f)
    {
        int x;
        cin >> x;
        mp[x]++;
        v[i] = x;
    }
    for (auto x : mp)
    {
        if (x.second % 2 != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    sort(v.begin(), v.end());
    ll area = v[0] * v.back();
    for (int i = 0; i < n; i++)
    {
        if (v[2 * i] * v[f -  2 * i - 1] != area)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
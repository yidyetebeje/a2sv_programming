#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9 + 7, N = 2e6 + 7, M = 2e6 + 7, INF = INT_MAX / 10;
ll powe(ll x, ll y)
{
    x = x % mod, y = y % (mod - 1);
    ll ans = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ans = (1ll * x * ans) % mod;
        }
        y >>= 1;
        x = (1ll * x * x) % mod;
    }
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<long long> dividers(m, 0);
    for (int i = 0; i < m; i++)
        cin >> dividers[i];
    long long sum = 2;
    if(n <= 2)
        cout << 0 << endl;
    
    else {
        sort(dividers.begin(), dividers.end(), [](auto a, auto b)
             { return a > b; });
        for (int i = 0; i < m; i++)
        {
            sum += dividers[i] - 1;
            if (sum >= n)
            {
                cout << i + 1 << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
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
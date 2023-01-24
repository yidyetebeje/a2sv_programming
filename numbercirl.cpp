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
}
signed main()
{
    fast;
    ll m, n, i, j, k;
    cin >> n;
    vector<ll> vi(n);
    for(int i = 0; i < n; i++)
        cin >> vi[i];
    sort(vi.begin(), vi.end());
    if (vi[n - 3] + vi[n - 2] <= vi[n - 1])
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << vi[n - 1] << " ";
        for (i = n - 3; i >= 0; i--)
            cout << vi[i] << " ";
        cout << vi[n - 2] << endl;
    }
}
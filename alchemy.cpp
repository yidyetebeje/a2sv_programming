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
void solve(vector<long long>& v)
{
    long long sumA = 0;
    long long sumB = 0;
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        if (sumA > sumB)
        {
            sumB += v[r];
            r--;
        }
        else
        {
            sumA += v[l];
            l++;
        }
    }
    cout << l << " " << (v.size() - r - 1) << endl;
}
signed main()
{
    fast;
    int t = 1;
    cin >> t;
    vector<long long> v(t, 0);
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }
    solve(v);
    return 0;
}
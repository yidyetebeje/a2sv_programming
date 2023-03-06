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
void solve(vector<string> & n, string& name)
{
    auto upperbound = upper_bound(n.begin(), n.end(), name);
    cout << upperbound - n.begin() << endl;
}
signed main()
{
    fast;
    int t = 1;
    int n = 0;
    cin >> n;
    vector<string> names(n,"");
    cin.ignore();
    for (int i = 0; i < n; i++){
        cin >> names[i];
    }
    cin >> t;
    while (t--)
    {
        cin.ignore();
        string name;
        cin >> name;
        solve(names, name);
    }
    return 0;
}
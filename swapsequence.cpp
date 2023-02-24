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
void solve(vector<int> vi)
{
    //selection sort
    int n = vi.size();
    int ans = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vi[j] < vi[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(vi[i], vi[min]);
            v.push_back({i, min});
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
}
signed main()
{
    fast;
    int t = 1;
    cin >> t;
    vector<int> vi(t);
    for(int i = 0; i < t; i++){
        cin >> vi[i];
    }
    solve(vi);
    return 0;
}
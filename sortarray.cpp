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
    int t = 1;
    cin >> t;
    vector<int> a(t);
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
    }
    bool count = 0;
    int l = 0, r = 0;
    if(is_sorted(a.begin(), a.end())){
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    while(l < t - 1 && a[l] <= a[l + 1]){
        l++;
    }
    r = l;
    while (r < t - 1 && a[r] >= a[r + 1])
    {
        r++;
    }
    reverse(a.begin() + l, a.begin() + r + 1);
    if(is_sorted(a.begin(), a.end())){
        cout << "yes" << endl;
        cout << l + 1 << " " << r + 1 << endl;
        return 0;
    }
    cout << "no" << endl;
    return 0;
}
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
void solve(string s)
{
    char t = s[0];
    string p;
    int count = 1;
    int l = 0, r = 1;
    if(s.size() == 1){
        cout << s << endl;
        return;
    }
    while (r < s.size())
    {
        if(s[l] != s[r]){
            if(count % 2 != 0) {
                p += s[l];
            }
            l = r;
            count = 1;
        }
        else
        {
            count++;
        }
        if(r == s.size() - 1 && count % 2 != 0)
            p += s[l];
        r++;
    }
    set<char> m(p.begin(), p.end());
    string newN(m.begin(), m.end());
    cout << newN << endl;
}
signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin.ignore();
        cin >> s;
        solve(s);
    }
    return 0;
}
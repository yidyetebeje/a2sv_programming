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
bool checkValid(vector<int> vi){
    for (int i = 0; i < vi.size(); i++){
        if(vi[i] == 0)
            return false;
    }
    return true;
}
void solve(string s)
{
    vector<int> vi(3, 0);
    int minW = INF;
    int l = 0, r = 0;
    while(r < s.size()){
        vi[(int)s[r] - 49] += 1;
        if (checkValid(vi))
        {
            minW = min(r - l + 1, minW);
            vi[s[l] - 49] -= 1;
            l++;
            while(l < s.size() && checkValid(vi)){
                minW = min(r - l + 1, minW);
                vi[s[l] - 49] -= 1;
                l++;
            }
        }
        r++;
    }
    if(minW == INF)
        minW = 0;
    cout << minW << endl;
}
signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
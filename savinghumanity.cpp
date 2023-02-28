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
    int n, p;
    string s;
    cin >> n >> p;
    cin.ignore();
    cin >> s;
    int l = 0, r = 1;
    int count = 0;
    while(r < s.size()){
        if(s[r] == '1'){
            if(s[l] == '0'){
                int y = p;
                int right = r - 1;
                while (l <= right && y--)
                {
                    s[right] = '1';
                    right--;
                }
            }
            else if(s[l] == '1'){
                int templ = l + 1, tempr = r - 1;
                int y = p;
                while(templ < tempr && y--){
                    s[templ] = '1';
                    s[tempr] = '1';
                    templ++, tempr--;
                }
            } 
            l = r;
        }
        else if (r == s.size() - 1 && s[l] == '1' && s[r] == '0')
        {
            int y = p;
            int left = l + 1;
            while (left <= r && y--)
            {
                s[left] = '1';
                left++;
            }
        }
        r++;
    }
    cout << s << endl;
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
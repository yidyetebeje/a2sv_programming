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
void solve(string & s)
{
    int n = s.size();
    int ans = 0;
    int l = 0, r = n - 1;
    vector<pair<int, int>> v;
    while(l <= r){
        if(s[l] == '(' && s[r] == ')'){
            v.push_back({l, r});
            l++;
            r--;
        }
        else if(s[l] == '(' && s[r] == '('){
            r--;
        }
        else if(s[l] == ')' && s[r] == ')'){
            l++;
        }
        else{
            l++;
            r--;
        }
    }
    if(v.size() == 0){
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    cout << v.size()* 2 << endl;
    for(auto x: v){
        cout << x.first + 1 << " ";
    }
    for(int i = v.size() - 1; i >= 0; i--){
        cout << v[i].second + 1 << " ";
    }
}
signed main()
{
    fast;
    string s;
    cin >> s;
    solve(s);
    return 0;
}
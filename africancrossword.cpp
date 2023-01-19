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
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2)
        {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};
void solve()
{
}
signed main()
{
    fast;
    int n, m;
    cin>>n>>m;
    vector<string> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    unordered_map<pair<int,char>,int,hash_pair> mp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mp[{i,v[i][j]}]++;
        }
    }
    unordered_map<pair<int,char>,int, hash_pair> mp2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mp2[{j,v[i][j]}]++;
        }
    }
    string ss;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++){
            if(mp[{i,v[i][j]}] == 1 && mp2[{j,v[i][j]}] == 1){
                ss += v[i][j];
            }
        }
    }
    cout << ss << endl;
}
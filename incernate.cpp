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
void solve(vector<vector<int>>& grid, int k)
{
    sort(grid.begin(),grid.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    });
    int a = 0;
    int j = 0;
    while(k < 0){
        if(j == grid[0].size()){
            break;
        }
        if(grid[1][j] > a){
            a += k;
            k -= grid[0][j];
        } else {
            while(grid[1][j] <= a){
                j++;
            }
        }
    }
    if(grid[1][j] <= a){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
signed main()
{
    fast;
    int t = 1;
    for (int i = 0; i < 2; i++)

        cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
                for (int i = 0; i < 2; i++)

                {
                    cin >> grid[i][j];
                }
        }
        solve(grid, m);
    }
    return 0;
}
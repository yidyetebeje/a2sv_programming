#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define PB push_back
#define MP make_pair
const ll mod = 1e9 + 7, N = 2e6 + 7, M = 2e6 + 7, INF = INT_MAX / 10;
void solve()
{
    int n;
    cin >> n;
    if(n == 1){
        cout << 3 << endl;
        return;
    }
    if(n & 1){
        cout << 1 << endl;
        return;
    }
    auto x = n & (-n);
    if (x == n)
    {
        cout << x  + 1<< endl;
        return;
    }
    cout << x << endl;
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
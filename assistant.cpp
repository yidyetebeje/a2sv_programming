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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    forn(i, m)
    {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < n; i++)
        if(a[i] == 0)
        {
            cout << "YES" << endl;
            return;
        }
    cout << "NO" << endl;
}
signed main()
{
    fast;
    solve();
    return 0;
}
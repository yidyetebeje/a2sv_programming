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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i, n)
    {
        cin >> a[i];
    }
    int l = 0, r = 0, ans = 0, cnt = 0;
    int tl = 0, tr = 0;
    map<int, int> mp;
    while (r < n)
    {
        if (mp[a[r]] == 0)
            cnt++;
        mp[a[r]]++;
        while (cnt > k)
        {
            mp[a[l]]--;
            if (mp[a[l]] == 0)
                cnt--;
            l++;
        }
        if(ans < r - l + 1)
        {
            ans = r - l + 1;
            tl = l;
            tr = r;
        }
        r++;
    }
    cout << tl + 1 << " " << tr + 1 << endl;
}
signed main()
{
    fast;
    int t = 1;
    solve();
    return 0;
}
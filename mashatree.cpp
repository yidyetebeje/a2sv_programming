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
int solve(int l, int r, vector<ll> & vi){
    if(r - l == 1){
        return 0;
    }
    int mid = l + (r - l) / 2;
    auto mal = *max_element(vi.begin() + l, vi.begin() + mid);
    auto mar = *max_element(vi.begin() + mid, vi.begin() + r);
    int ans = 0;
    if (mal > mar)
    {
        ans = 1;
        for (int i = 0; i < (mid - l); ++i)
            swap(vi[l + i], vi[mid + i]);
    }
    return ans + solve(l, mid, vi) + solve(mid, r, vi);
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> vi(n);
    for(int i = 0; i < n; i++){
        cin >> vi[i];
    }
    int ans = solve(0, n, vi);
    if(is_sorted(vi.begin(), vi.end())){
        cout << ans << endl;
        return;
    } else {
        cout << -1 << endl;
    }
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
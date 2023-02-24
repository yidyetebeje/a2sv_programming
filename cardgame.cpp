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
}
signed main()
{
    fast;
    int t = 1;
    cin >> t;
    vector<int> vi(t);
    for (int i = 0; i < t; i++){
        cin >> vi[i];
    }
    int firstScore = 0;
    int secondScore = 0;
    int turn = 0;
    int l = 0, r = vi.size() - 1;
    while (l <= r)
    {
        if(vi[l] > vi[r]){
            if(turn == 0){
                firstScore += vi[l];
                turn = 1;
            }
            else
            {
                secondScore += vi[l];
                turn = 0;
            }

            l++;
        } else {
            if (turn == 0)
            {
                firstScore += vi[r];
                turn = 1;
            }
            else{
                secondScore += vi[r];
                turn = 0;
            }
            r--;
        }
    }
    cout << firstScore << " " << secondScore;
    return 0;
}
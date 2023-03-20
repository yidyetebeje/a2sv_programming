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
#define limit pow(2, 32) - 1
stack<ll> st;
bool overflow = false;
void solve()
{
    int t;
    ll total = 0;
    st.push(1);
    cin >> t;
    while (t--)
    {
        string s;
        ll n;
        cin >> s;
        if (s == "for")
        {
            cin >> n;
            ll top= st.top();
            if (top== -1)
                st.push(-1);
            else if (top* n > limit)
                st.push(-1);
            else
                st.push(top* n);
        }
        if (overflow == false)
        {
            if (s == "add")
            {
                if (st.top() != -1)
                    total += st.top();
                else
                    overflow = true;
            }
            if (s == "end")
            {
                st.pop();
            }
        }
        if (total > limit)
        {
            overflow = true;
        }
    }
    if (!overflow)
        cout << total << endl;
    else
        cout << "OVERFLOW!!!" << endl;
}
signed main()
{
    fast;
    solve();
    return 0;
}
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
}
signed main()
{
    fast;
    int n;
    cin >> n;
    unordered_set<string> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                string s = to_string(i) + " " + to_string(j);
                string s1 = to_string(j) + " " + to_string(i);
                st.insert(s);
                st.insert(s1);
            }
        }
    }
    cout << st.size()/2 << endl;
}
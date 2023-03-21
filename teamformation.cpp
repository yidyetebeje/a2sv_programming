#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve() {
    ll a, b;
    cin >> a >> b;
    cout << min(min(a, b), (a + b) / 4) << '\n';
}
 
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
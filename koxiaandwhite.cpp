#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve(){
    long long n,m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        pq.push(x);
    }
    for(long long i = 0; i < m; i++){
        long long x;
        pq.pop();
        cin >> x;
        pq.push(x);
    }
    long long ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
}

    
signed main(){
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

void solve(){
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x > 0){
            pq.push({x, i});
        }
    }
    vector<pair<int, int>> res;
    while(pq.size() > 1){
        auto p1 = pq.top();
        pq.pop();
        auto p2 = pq.top();
        pq.pop();
        res.push_back({p1.second, p2.second});
        p1.first--;
        p2.first--;
        if(p1.first > 0){
            pq.push(p1);
        }
        if(p2.first > 0){
            pq.push(p2);
        }
    }
    cout << res.size() << endl;
    for(auto it : res){
        cout << it.first + 1 << " " << it.second + 1 << endl;
    }
}
int main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
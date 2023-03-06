#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed atMost(vector<ll>& v, int k){
    int l = 0, r = 0;
    int sum = 0;
    int count = 0;
    while(r < v.size()){
        sum += v[r];
        while(sum > k){
            sum -= v[l];
            l++;
        }
        count += r - l + 1;
        r++;
    }
    return count;
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> ans(n);
    for (int i = 0; i < n;i++)
        cin >> ans[i];
    int c = atMost(ans, a - 1);
    int d = atMost(ans, b);
    cout << d - c<< endl;
}
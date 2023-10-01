#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ibsa(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> ibsa[i];
    }
    sort(v.begin(), v.end());
    sort(ibsa.begin(), ibsa.end());
    int l = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(l < n && v[i] > ibsa[l]){
            l++;
        }
        if(l == n){
            break;
        }
        ans++;
    }
    int win = n /2;
    if(ans > win){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
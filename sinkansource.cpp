#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int main(){
    fast;
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    vector<int> sinks;
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < n; j++){
            if(v[i][j] == 1){
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            sinks.push_back(i);
    }
    vector<int> sources;
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < n; j++){
            if(v[j][i] == 1){
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            sources.push_back(i);
    }
    sort(sinks.begin(), sinks.end());
    sort(sources.begin(), sources.end());
    cout << sources.size();
    for(int i = 0; i < sources.size(); i++){
        cout << " " << sources[i] + 1;
    }
    cout << endl;
    cout << sinks.size();
    for(int i = 0; i < sinks.size(); i++){
        cout << " " << sinks[i] + 1;
    }
    cout << endl;
}
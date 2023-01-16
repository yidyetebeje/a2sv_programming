#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

int xsum(vector<vector<int>>& matrix){
    int rsize = matrix.size();
    int csize = matrix[0].size();
    vector<int> maindiagonal(rsize + csize - 1, 0);
    vector<int> crossdiagonal(rsize + csize - 1,0);
    for(int i = 0; i < rsize; i++){
        for(int j = 0; j < csize; j++){
            maindiagonal[i - j + csize - 1] += matrix[i][j];
            crossdiagonal[i + j] += matrix[i][j];
        }
    }
    int max = 0;
    for(int i = 0; i < rsize;i++){
        for(int j = 0; j < csize; j++){
            int sum = maindiagonal[i - j + csize - 1] + crossdiagonal[i + j] - matrix[i][j];
            if(sum > max) max = sum;
        }
    }
    return max;
}

int main(){
    fast;
    int t;
    cin >> t;
    for(int i = 0; i < t;i++){
        int rsize, csize;
        cin >> rsize >> csize;
        vector<vector<int>> matrix(rsize, vector<int>(csize,0));
        for(int j = 0; j < rsize; j++){
            for(int k = 0; k < csize; k++){
                cin >> matrix[j][k];
            }
        }
        cout << xsum(matrix) << endl;
    }
}
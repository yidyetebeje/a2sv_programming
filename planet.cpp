#include <bits/stdc++.h>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int queries;
  cin >> queries;
  for(int i = 0; i < queries; i++){
    int n,m;
    cin>>n>>m;
    int sum = 0;
    int l;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
      cin >> l;
      mp[l]++;
    }
    for(auto val: mp){
      if(val.second < m){
          sum += val.second;
      } else sum += m;
    }
    cout << sum << "\n";
  }
}
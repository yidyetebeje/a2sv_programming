class UnionFind {
public:
  vector<int> parent;
  vector<int> rank;

  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void union_sets(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
      return;
    }

    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) {
        rank[x]++;
      }
    }
  }

  bool is_same_set(int x, int y) {
    return find(x) == find(y);
  }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UnionFind uf(n);
        for(auto pair: pairs){
            uf.union_sets(pair[0], pair[1]);
        }
        unordered_map<int, map<int,int>> mp;
        for(int i = 0; i < n; i++){
            mp[uf.find(i)][s[i]]++;
        }
        string l = "";
        for(int i = 0; i < n; i++){
            auto it = mp[uf.find(i)].begin();
            int min_value = it->first;
            l += min_value;
            mp[uf.find(i)][min_value]--;
            if(mp[uf.find(i)][min_value] == 0){
              mp[uf.find(i)].erase(min_value);
            }
        }
        return l;
    }
};
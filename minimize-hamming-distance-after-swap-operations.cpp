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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowed_swaps) {
        int n = source.size();
        UnionFind uf(n);
        for (auto allowed_swap : allowed_swaps) {
            uf.union_sets(allowed_swap[0], allowed_swap[1]);
        }
        unordered_map<int,unordered_map<int,int>> mp;
        for(int i = 0; i < n; i++){
          mp[uf.find(i)][source[i]]++;
        }
        int hamming = n;
        for(int i = 0; i < n; i++){
            auto& freq = mp[uf.find(i)];
            if(freq.find(target[i]) == freq.end()) continue;
            else {
                hamming--;
                freq[target[i]]--;
                if(freq[target[i]] == 0){
                    freq.erase(target[i]);
                }
            }
        }
        return hamming;
    }
};
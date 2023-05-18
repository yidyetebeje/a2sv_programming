struct UnionFind {
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
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (rank[x] < rank[y]) {
        parent[x] = y;
      } else {
        parent[y] = x;
        if (rank[x] == rank[y]) {
          rank[x]++;
        }
      }
    }
  }

  bool is_connected(int x, int y) {
    return find(x) == find(y);
  }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
          for (int j = i + 1; j < n; j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
              uf.union_sets(i, j);
            }
          }
      }
      unordered_set<int> sets;
      for (int i = 0; i < n; i++) {
        sets.insert(uf.find(i));
      }
      return n - sets.size();
    }
};
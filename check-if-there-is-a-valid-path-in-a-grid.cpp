struct PairHash {
  size_t operator()(const pair<int, int>& p) const {
    return p.first * 1000000 + p.second;
  }
};

class UnionFind {
public:
  unordered_map<pair<int, int>, pair<int, int>,PairHash> parent;
  unordered_map<pair<int, int>, int, PairHash> rank;

  UnionFind(int row, int col) {
    for (int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++){
            parent[make_pair(i, j)] = make_pair(i, j);
            rank[make_pair(i, j)] = 0;
        }
    }
  }
  UnionFind(){};

  pair<int, int> find(pair<int, int> x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unionSet(pair<int, int> x, pair<int, int> y) {
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

  bool isSameSet(pair<int, int> x, pair<int, int> y) {
    return find(x) == find(y);
  }
};

class Solution {
public:
bool isBound(int x, int y, int width, int height) {
  return (x >= 0 && x < width && y >= 0 && y < height);
}

    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>> mp = {
            {1, {1,1,0,0}},
            {2, {0,0,1,1}},
            {3, {1,0,0,1}},
            {4, {0,1,0,1}},
            {5, {1,0,1,0}},
            {6, {0,1,1,0}}
        };
        int row = grid.size();
        int col = grid[0].size();
        auto* un = new UnionFind(row, col);
        vector<pair<int,int>> dir = {{0,1}, {1, 0}};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                auto r = grid[i][j];
                for(int k = 0; k < 2;k++){
                    auto pos = make_pair(i + dir[k].first, j + dir[k].second);
                    if(isBound(pos.first, pos.second, row, col)){

                        auto x = grid[pos.first][pos.second];
                        if(k == 0 && mp[x][0] == 1 && mp[r][1] == 1){
                            un->unionSet(pos, {i, j});
                        } else if(k == 1 && mp[r][3] == 1 && mp[x][2] == 1){
                            un->unionSet(pos, {i, j});
                        }
                    }
                }
            }
        }

        return un->isSameSet(make_pair(0, 0), make_pair(row - 1, col -1));
    }
};
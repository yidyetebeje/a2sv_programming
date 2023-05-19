struct PairHash {
  size_t operator()(const pair<int, int>& p) const
    {
        auto hash1 = hash<int>{}(p.first);
        auto hash2 = hash<int>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

class UnionFind {
public:
  unordered_map<pair<int, int>, pair<int, int>,PairHash> parent;
  unordered_map<pair<int, int>, int, PairHash> rank;

  UnionFind(vector<vector<int>>& points) {
    for (int i = 0; i < points.size(); i++) {
        parent[make_pair(points[i][0], points[i][1])] = make_pair(points[i][0], points[i][1]);
        rank[make_pair(points[i][0], points[i][1])] = 0;
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

struct Edge {
    pair<int,int> u, v;
    int weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        auto* un = new UnionFind(points);
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                Edge edge;
                edge.u = {points[i][0], points[i][1]};
                edge.v = {points[j][0], points[j][1]};
                edge.weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back(edge);
            }
        }
        sort(edges.begin(), edges.end());
        int cost = 0;
        for (Edge e : edges) {
            if (un->find(e.u) != un->find(e.v)) {
                cost += e.weight;
                un->unionSet(e.u, e.v);
            }
        }
        return cost;
    }
};
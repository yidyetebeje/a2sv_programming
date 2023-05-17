class UnionFind {
public:
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

    void unionSet(int x, int y) {
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

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    private:
        vector<int> parent;
        vector<int> rank;
    };

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        auto* un = new UnionFind(edges.size() + 1);
        for(auto edge: edges){
            int x = un->find(edge[0]);
            int y =  un->find(edge[1]);
            if(x == y) return edge;
            else un->unionSet(edge[0], edge[1]);
        } 
        return vector<int>{};
    }
};
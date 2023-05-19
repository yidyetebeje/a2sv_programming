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
    int count(unordered_map<int,int>& st){
        int x = find(1);
       
        int minVal = st[x];
        for(int i = 0; i < parent.size(); i++){
            int y = find(i);
            if(x == y){
                
                minVal = min(minVal,st[i]);
            }
        }
        return minVal;
    }
    private:
        vector<int> parent;
        vector<int> rank;
    };
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        auto* un = new UnionFind(n + 1);
        unordered_map<int,int> st; 
        for(auto road: roads){
            un->unionSet(road[0], road[1]);
            if(st.count(road[0])) st[road[0]] = min(st[road[0]], road[2]);
            else st[road[0]] = road[2];
            if(st.count(road[1])) st[road[1]] = min(st[road[1]], road[2]);
            else st[road[1]] = road[2];
        }
        return un->count(st);

    }
};
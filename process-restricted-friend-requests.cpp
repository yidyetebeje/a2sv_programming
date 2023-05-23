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
    bool canBeFriend(UnionFind* uf, vector<vector<int>>& restrictions, pair<int,int> p){
        for(auto& rest : restrictions){
            if((uf->isSameSet(rest[0], p.first) && uf->isSameSet(rest[1], p.second)) || (uf->isSameSet(rest[1], p.first) && uf->isSameSet(rest[0], p.second))){
                return false;
            }
        }
        return true;
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        UnionFind* uf = new UnionFind(n);
        vector<bool> ans(requests.size());
        int i = 0;
        for(auto& request: requests){
            auto res = canBeFriend(uf, restrictions, {request[0], request[1]});
            if(res) uf->unionSet(request[0], request[1]);
            ans[i++] = res;
        }
        return ans;
    }
};
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
        if (parent[x] == x) {
            return x;
        }
        int root = find(parent[x]);
        parent[x] = root;
        return root;
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
    char getAllConnectedElements(int x) {
        int minVal = x;
        int current = find(x);
        for(int i = 0; i < parent.size(); i++){
            if(parent[i] == current){
                minVal = min(minVal, i);
            }
        }
        return minVal + 'a';
    }
 
    private:
        vector<int> parent;
        vector<int> rank;
    };
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        auto* un = new UnionFind(26);
        for(int i = 0; i < s1.size(); i++){
            un->unionSet(s1[i] - 'a', s2[i] - 'a');
        }
        string s = "";
        s.resize(baseStr.size());
        for(int i = 0; i < baseStr.size();i++){
            s[i] = un->getAllConnectedElements(baseStr[i] - 'a');
        }
        return s;
    }
};
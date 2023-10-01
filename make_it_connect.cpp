#include <bits/stdc++.h>
using namespace std;
struct Edge {
    pair<int,int> u;
    long long weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
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

int main(){
    
    int n,m;
    cin >> n >> m;
	vector<long long> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<Edge> edges(m);
	for(int i = 0; i < m; i++)
	{
		cin >> edges[i].u.first >>edges[i].u.second  >>edges[i].weight;
		edges[i].u.first--;
		edges[i].u.second--;
	}
	int z = min_element(a.begin(), a.end()) - a.begin();
	for(int i = 0; i < n; i++)
		if(i != z)
			edges.push_back({make_pair(i,z), a[i] + a[z]});
    sort(edges.begin(), edges.end());
    long long ans = 0;
    UnionFind un(n + 1);
    for (Edge e : edges) {
        if (!un.isSameSet(e.u.first, e.u.second)) {
            ans += e.weight;
            un.unionSet(e.u.first, e.u.second);
        }
    }
    cout << ans << endl;
}
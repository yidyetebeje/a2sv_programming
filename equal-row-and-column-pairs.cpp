class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int nrows=grid.size();
        int ncols=grid[0].size();
        
        map<vector<int>,int>m;
        
        for(auto &r:grid) {
            m[r]++;
        }
        int ans = 0;
        for(int j=0;j<ncols;j++) {
            vector<int> t;
            for(int i=0;i<nrows;i++) {
                t.push_back(grid[i][j]);
            }
            ans += m[t];
        }
        return ans;
    }
};
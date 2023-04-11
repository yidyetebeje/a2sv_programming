class Solution {
public:
    vector<pair<int,int>> directions {make_pair(0,1),make_pair(1,0), make_pair(0,-1), make_pair(-1, 0)};
    bool inbound(pair<int, int> p, int row, int col){
        return ((p.first >= 0 && p.first < row) && (p.second >= 0 && p.second < col));
    }
    void dfs(vector<vector<int>>& grid, pair<int,int> cor, vector<vector<bool>>& visited, int& r){
        r++;
        visited[cor.first][cor.second] = true;
        for(auto d: directions){
            auto p = make_pair(cor.first + d.first, cor.second + d.second);
            if(inbound(p, grid.size(), grid[0].size()) && visited[p.first][p.second] == false && grid[p.first][p.second] == 1){
                dfs(grid, p, visited, r);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size();j++){
                if(visited[i][j] == false && grid[i][j] == 1){
                    int r = 0;
                    dfs(grid, make_pair(i, j), visited,r);
                    res = max(res, r);
                }
            }
        }
        return res;
    }
};
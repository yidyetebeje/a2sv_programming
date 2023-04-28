class Solution {
public:
    vector<pair<int,int>> directions {make_pair(0,1),make_pair(1,0), make_pair(0,-1), make_pair(-1, 0)};
    bool inbound(pair<int, int> p, int row, int col){
        return ((p.first >= 0 && p.first < row) && (p.second >= 0 && p.second < col));
    }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& is_sub_island) {
        int rows = grid2.size();
        int cols = grid2[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return;
        }
        if (grid2[i][j] == 0) {
            return;
        }
        if (grid1[i][j] == 0) {
            is_sub_island = false;
        }
        grid2[i][j] = 0;
        dfs(grid1, grid2, i, j+1, is_sub_island);
        dfs(grid1, grid2, i, j-1, is_sub_island);
        dfs(grid1, grid2, i+1, j, is_sub_island);
        dfs(grid1, grid2, i-1, j, is_sub_island);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid2[i][j] == 1) {
                    bool is_sub_island = true;
                    dfs(grid1, grid2, i, j, is_sub_island);
                    count += is_sub_island ? 1 : 0;
                }
            }
        }
        
        return count;
    }
};
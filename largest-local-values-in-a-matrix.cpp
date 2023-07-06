class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int r = grid.size() - 2;
        vector<vector<int>> ans(r, vector<int>(r));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < r; j++){
                int maxN = 0;
                int max1 = max({grid[i][j], grid[i][j + 1], grid[i][j + 2]});
                int max2 = max({grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2]});
                int max3 = max({grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]});
                maxN  = max({max1, max2, max3});
                ans[i][j] = maxN;
            }
        }
        return ans;
    }
};
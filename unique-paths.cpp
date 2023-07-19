class Solution {
public:
    int recursive(int m, int n, int i, int j,vector<vector<int>>& dp){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = recursive(m,n, i + 1, j, dp) + recursive(m,n, i, j + 1, dp);
        return dp[i][j];
    }
    int tabulation(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n,1));
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
    int uniquePaths(int m, int n) {
       return tabulation(m,n);
    }
};
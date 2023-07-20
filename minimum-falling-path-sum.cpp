class Solution {
public:
    int n;
    int recursive(vector<vector<int>>& matrix,int col, int row, vector<vector<int>>& dp){
        if(col < 0 || col >= n) return INT_MAX;
        if(row == n - 1) return matrix[row][col];
        if(dp[row][col] != 20000) return dp[row][col];
        dp[row][col] = matrix[row][col] + min({recursive(matrix, col - 1, row +  1,dp), recursive(matrix, col + 1, row +  1,dp), recursive(matrix, col, row +  1,dp)});
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minAns = INT_MAX;
        n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 20000));
        for(int i = 0;i < n;i++){
            int res = recursive(matrix, i,0,dp);
            minAns = min(minAns, res);
        }
        return minAns;
    }
};
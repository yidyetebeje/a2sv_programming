class Solution {
public:
    int recursive(int row, int col, vector<vector<int>>& triangle,  vector<vector<int>>& dp){
        if(row == triangle.size()){
            return 0;
        }
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = min(recursive(row + 1,col, triangle,dp),recursive(row + 1, col + 1, triangle,dp)) + triangle[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(),-1));
        return recursive(0,0, triangle,dp);
    }
};
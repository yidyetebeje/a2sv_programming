class Solution{
    int memoization(int n,int m,vector<vector<int>> &dp,vector<vector<int>> &costs){
        if(n == 0 and m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        int a = 1e9;
        int b = 1e9;

        if(n > 0) a = memoization(n - 1,m,dp,costs) + costs[n + m - 1][0];
        if(m > 0) b = memoization(n,m - 1,dp,costs) + costs[n + m - 1][1];
        
        return dp[n][m] = min(a,b);
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
		
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,-1));
        return memoization(n,n,dp,costs);
    }
};
int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int mod = 1e9 + 7;
class Solution {
public:
    int recursive(int i, int j, int n,vector<vector<vector<int>>>& dp){
        if(i < 0 || j < 0 || j >= 3 || i >= 4) return 0;
        if((i == 3 && j == 0) || (i == 3 && j == 2)) return 0;
        
        if(n == 1) return 1;
        if(dp[i][j][n] != -1) return dp[i][j][n];
        int ans = 0;
        for(int k = 0; k < 8;k++){
            ans = ans % mod + (recursive(i + X[k], j + Y[k], n-1, dp) % mod);
        }
        return dp[i][j][n] = ans % mod;
    }
    int knightDialer(int n) {
        int ans = 0;
        vector<vector<vector<int>>> dp(4,vector<vector<int>>(3, vector<int>(n +1 , -1)));
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                ans = ans % mod + recursive(i, j, n, dp) % mod;
            }
        }
        return ans;
    }
};
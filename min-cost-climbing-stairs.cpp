class Solution {
public:
    int recursive(vector<int>& cost, int i, vector<int>& dp){
        if(i == 0 || i == 1){
            return cost[i];
        }
        if(dp[i] != -1) return dp[i];
        dp[i] = min(recursive(cost, i - 1, dp) + cost[i], recursive(cost, i - 2, dp) + cost[i]);
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(cost.size(), -1);
        return recursive(cost, cost.size() - 1, dp);
    }
};
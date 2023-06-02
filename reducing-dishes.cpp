class Solution {
public:
    int recursive(int i, int count, vector<int>& s, vector<vector<int>>& dp){
        if(i == s.size()){
            return 0;
        }
        if(dp[i][count] != -1) return dp[i][count];
        return dp[i][count] = max(s[i] * count + recursive(i + 1,count + 1,s,dp), recursive(i + 1, count, s,dp));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size() + 1, -1));
        return recursive(0, 1, satisfaction, dp);
    }
};
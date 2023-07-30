class Solution {
public:
    long long recursive(vector<vector<int>>& questions, int index,vector<long long>& dp){
        if(index >= questions.size()) return 0;
        if(dp[index] != -1) return dp[index];
        long long notTakeIt = recursive(questions, index + 1,dp);
        long long takeIt = questions[index][0] + recursive(questions,index + questions[index][1] + 1,dp);
        return dp[index] = max(takeIt, notTakeIt);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
       return recursive(questions, 0, dp);
    }
};
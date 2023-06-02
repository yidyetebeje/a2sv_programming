class Solution {
public:
    int backtrack(vector<int>& nums,int target, vector<int>& dp){
        if(target== 0){
            return 1;
        } else if(target < 0){
            return 0;
        }
        if(dp[target]!= -1){
            return dp[target];
        }
        int count = 0;
        for(auto num: nums){
            count += backtrack(nums,target-num, dp);
        }
        return dp[target] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return backtrack(nums,target, dp);
    }
};
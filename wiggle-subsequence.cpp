class Solution {
public:
    int recursive(vector<int>& nums,int index,bool isUp, vector<vector<int>>& dp){
        int maxcount = 0;
        int i = isUp;
        if(dp[index][i] != -1){
            return dp[index][i];
        }
        for(int i = index + 1; i < nums.size(); i++){
            if((isUp && nums[i] > nums[index]) || (!isUp && nums[i] < nums[index])){
                maxcount = max(maxcount, 1 + recursive(nums,i, !isUp,dp));
            }
        }
        return dp[index][i] = maxcount;
    }
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2){
            return nums.size();
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        return 1 + max(recursive(nums, 0, true, dp) , recursive(nums, 0, false, dp));
    }
};
class Solution {
public:
    int recursive(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i == n){
            return  nums[i];
        } else if(i > n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        dp[i] = max(recursive(nums, i + 2,n,dp), recursive(nums, i + 3,n,dp)) + nums[i];
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        if(nums.size() == 1) return nums[0];
        int x = recursive(nums, 0, nums.size() - 2,res);
        res.assign(nums.size(), -1);
        int y = recursive(nums, 1, nums.size() - 1,res);
        res.assign(nums.size(), -1);
        int z = nums.size() >= 3 ? recursive(nums, 2, nums.size() - 1, res): 0;
        return max({x, y, z});
    }
};
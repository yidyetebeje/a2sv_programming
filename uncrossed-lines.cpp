class Solution {
public:
    int recursive(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(i == nums1.size() || j == nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + recursive(i + 1, j + 1, nums1, nums2, dp);
        }

        return dp[i][j] = max({recursive(i, j + 1, nums1, nums2, dp), recursive(i + 1, j, nums1, nums2, dp), recursive(i + 1, j + 1, nums1, nums2, dp)});
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), - 1));
        return recursive(0, 0, nums1, nums2, dp);
    }
};
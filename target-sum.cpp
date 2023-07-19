class Solution {
public:
    struct pair_hash {
        template <typename T1, typename T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
  int recursive(vector<int>& nums, int sum, int i, int target,unordered_map<pair<int,int>,int, pair_hash>& dp){
      if(i == nums.size()){
          if(sum == target){
              return 1;
          }
          return 0;
      }
      if(dp.count({sum, i})) return dp[{sum, i}];
      dp[{sum ,i}] = recursive(nums, sum + nums[i], i + 1, target,dp) + recursive(nums, sum - nums[i], i + 1, target,dp);
      return dp[{sum , i}];
  }
  int findTargetSumWays(std::vector<int> nums, int S) {
      unordered_map<pair<int,int>,int, pair_hash> dp;
      return recursive(nums, 0, 0, S,dp);
  }
};
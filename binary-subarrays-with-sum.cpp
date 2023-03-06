class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp{{0,1}};
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(mp.count(sum - goal)) count += mp[sum - goal];
            mp[sum]++;
        }
        return count;
    }
};
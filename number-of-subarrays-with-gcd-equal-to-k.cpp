class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int g = nums[i];
            for(int j = i; j < nums.size(); j++){
                if(nums[j] % k != 0) break;
                g = gcd(g, nums[j]);
                if(g == k) ans++;
            }
        }
        return ans;
    }
};
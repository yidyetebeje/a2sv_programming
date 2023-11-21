class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto num:nums){
            string rev = to_string(num);
            reverse(rev.begin(), rev.end());
            int reversed = stoi(rev);
            if(mp.count(num - reversed)){
                ans = (ans + mp[num - reversed]) % (int)(1e9 + 7);
            }
            mp[num - reversed]++;
        }
        return ans % (int)(1e9 + 7);
    }
};
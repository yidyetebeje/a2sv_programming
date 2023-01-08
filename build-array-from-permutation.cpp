class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> r(nums.size());
        for(int i = 0; i < nums.size(); i++){
            r[i] = nums[nums[i]];
        }
        return r;
    }
};
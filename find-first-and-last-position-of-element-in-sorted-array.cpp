class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(),nums.end(),target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        if(!binary_search(nums.begin(), nums.end(),target)) return vector<int>{-1, -1};
        return vector<int>{static_cast<int>(lower - nums.begin()),static_cast<int>(upper - nums.begin()) - 1};
    }
};
class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto x = *max_element(nums.begin(), nums.end());
        auto y = *min_element(nums.begin(), nums.end());
        return gcd(x, y);
    }
};
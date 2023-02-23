class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums)
{
    int minW = INT32_MAX;
    long long sum = 0;
    int r = 0, l = 0;
    while(r < nums.size()){
        sum += nums[r];
        while(sum >= target){
            sum -= nums[l];
            minW = min(minW, (r-l + 1));
            l++;
        }
        r++;
    }
    return minW == INT32_MAX ? 0: minW;
}
};
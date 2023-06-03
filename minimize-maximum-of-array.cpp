class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long maxEl = 0;
        long long sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            long long avg = (sum + i)/(i + 1);
            maxEl = max(maxEl,avg);
        }
        return maxEl;
    }
};
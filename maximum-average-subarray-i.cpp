class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i < k - 1; i++){
            sum += nums[i];
        }
        double maxA = INT32_MIN;
        int l = 0, r = k - 1;
        while(r < nums.size()){
            sum += nums[r];
            maxA = max(maxA, sum / k);
            sum -= nums[l];
            l++;
            r++;
        }
        return maxA;
    }
};
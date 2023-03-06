class Solution {
public:
    int average(vector<int>& nums, int k){
        int sum = 0;
        for(auto v: nums){
            sum += ceil((1.0*v)/k);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while(r -  l > 1){
            int m = l + (r - l)/2;
            int div = average(nums, m);
            if(div <= threshold){
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
};
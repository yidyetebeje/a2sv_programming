class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        for(int i = 0, sz = nums.size(); i != sz; ++i) {
            auto& n = nums[i];
            while(n != i+1) {
                if(nums[n-1] == n) {
                    result[0] = n;
                    result[1] = i+1;
                    break;
                }
                swap(n, nums[n-1]);
            }
        }
        return result;
    }
};
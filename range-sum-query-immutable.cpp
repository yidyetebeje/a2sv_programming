class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
       prefixSum.resize(nums.size() + 1);
       partial_sum(nums.begin(), nums.end(), prefixSum.begin() + 1);
    }
    
    int sumRange(int left, int right) {
        return (prefixSum[right + 1] - prefixSum[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
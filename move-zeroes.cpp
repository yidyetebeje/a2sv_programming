class Solution {
public:
    void moveZeroes(vector<int> &nums){
    int start = 0, end = 0;
    for (end = 0; end < nums.size(); end++){
        if(nums[end] != 0){
            swap(nums[start], nums[end]);
            start++;
        }
    }
}
};
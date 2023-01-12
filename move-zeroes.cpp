class Solution {
public:
    void moveZeroes(vector<int> &nums){
    int start = 0, end = 0;
    for (end = 0; end < nums.size(); end++){
        if(nums[end] != 0){
            nums[start] = nums[end];
            start++;
        }
    }
    for (int i = start; i < nums.size(); i++){
        nums[i] = 0;
    }
}
};
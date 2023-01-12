class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int start = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[start] = nums[i];
                start++;
            }
        }
        for(int i = start; i < nums.size(); i++){
            nums[i] = 0;
        }
        return nums;
    }
};
class Solution {
public:
    vector<vector<int>> subsetS;
    void backTrack(vector<int>& nums,int i, vector<int>& subset){
        if(i == nums.size()){
            subsetS.push_back(subset);
            return;
        }
        if(i > nums.size()) return;
        subset.push_back(nums[i]);
        backTrack(nums, i + 1, subset);
        subset.pop_back();
        backTrack(nums, i + 1, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backTrack(nums, 0, subset);
        return subsetS;
    }
};
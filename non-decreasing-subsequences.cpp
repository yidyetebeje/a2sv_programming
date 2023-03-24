class Solution {
public:
    vector<vector<int>> subsequences;
    void backTrack(int start, vector<int>& vi, vector<int>& nums){
        if(vi.size() > 1) {
            subsequences.push_back(vi);
        }
        unordered_set<int> s;
        for(int i = start; i < nums.size(); i++){
            if(((vi.size() > 0 && nums[i] >= vi.back()) || vi.size() == 0) && s.find(nums[i]) == s.end()){
                vi.push_back(nums[i]);
                backTrack(i + 1, vi, nums);
                vi.pop_back();
                s.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> vi;
        backTrack(0, vi, nums);
        return subsequences;   
    }
};
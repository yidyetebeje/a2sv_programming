class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> cs(n + 1);
        vector<int> al;
        for(int i = 0; i < n; i++){
            cs[nums[i]] += 1;
        }
        for(int i = 0; i < cs.size(); i++){
            if(cs[i] == 2){
                al.push_back(i);
            }
        }
        return al;

    }
};
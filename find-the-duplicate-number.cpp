class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> cnt(nums.size(),0);
        int ind =  0;
        for(int i = 0; i<nums.size(); i++)
        {
            cnt[nums[i]]++;
        }
        
        for(int i = 0; i<cnt.size(); i++)
        {
            if(cnt[i] > 1)
            {
                ind  = i;
                break;
            }
        }
        
        return ind;
    }
};
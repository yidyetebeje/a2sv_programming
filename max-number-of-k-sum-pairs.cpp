class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r= nums.size() -1;
        int count = 0;
        while(l < r){
            if(nums[l] + nums[r] == k){
                count++;
                r--;
                l++;
            } else if(nums[l] + nums[r] > k){
                r--;
            } else{
                l++;
            }
        }   
        return count;
    }
};
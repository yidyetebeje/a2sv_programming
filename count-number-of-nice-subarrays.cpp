class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k)
{
    int count = 0;
    int n = nums.size();
    deque<int> dq;
    int l = 0, r = 0;
    int goodSub = 0;
    while(r < nums.size()){
        if(nums[r]%2 != 0) dq.push_back(r);
        if(dq.size() == k){
            r++;
            while(r < nums.size() && nums[r] % 2 == 0){
                r++;
            }
            int left = dq.front();
            int right = dq.back();
            goodSub += (left - l + 1) * (r - right);
            l = left + 1;
            dq.pop_front();
        } else r++;
    }
    return goodSub;
}
};
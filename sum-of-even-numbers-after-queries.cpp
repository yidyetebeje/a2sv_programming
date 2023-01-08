class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> vb;
        for(auto n : nums){
            if (n % 2 == 0){
                sum += n;
            }
        }
        for(auto q : queries){
            int i = q[1];
            int temp = nums[i];
            nums[i] = nums[i] + q[0];
            if (temp % 2 == 0 && nums[i] % 2 == 0){
                sum += q[0];
            } else if(temp % 2 == 0 && nums[i] % 2 != 0){
                sum -= temp;
            } else if(temp % 2 != 0 && nums[i] % 2 == 0){
                sum += nums[i];
            }
            vb.push_back(sum);
        } 
        return vb; 
    }
};
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> myset;
        for(int i = 0; i < nums.size();i++){
            string num = to_string(nums[i]);
            reverse(num.begin(), num.end());
            int rev = stoi(num);
            myset.insert(nums[i]);
            myset.insert(rev);
        }
        return myset.size();
    }
};
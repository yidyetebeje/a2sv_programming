class Solution {
public:
    vector<int> primeFactors(int n){
            vector<int> res;
            while (n % 2 == 0)
            {
                res.push_back(2);
                n = n/2;
            }
        for (int i = 3; i <= sqrt(n); i = i + 2)
            {
                while (n % i == 0)
                {
                    res.push_back(i);
                    n = n/i;
                }
            }
            if (n > 2){
                res.push_back(n);
            }
        return res;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> myset;
        for(int i = 0; i < nums.size(); i++){
            auto res = primeFactors(nums[i]);
            std::copy(res.begin(), res.end(), std::inserter(myset, myset.end()));
        }   
        return myset.size();
    }
};
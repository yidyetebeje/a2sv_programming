#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int subarraySum(vector<int> &nums, int k){
            int count = 0, sum = 0;
            unordered_map<int, int> mp{{0,1}};
            for(auto num: nums){
                sum += num;
                if(mp.count(sum - k)) count += mp[sum - k];
                mp[sum]++;
            }
            return count;
        }
};
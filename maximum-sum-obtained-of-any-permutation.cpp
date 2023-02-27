#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
        {
            int n = nums.size();
            vector<int> freq(n, 0);
            for (auto &request : requests)
            {
                freq[request[0]]++;
                if (request[1] + 1 < n)
                    freq[request[1] + 1]--;
            }
            for (int i = 1; i < n; i++)
                freq[i] += freq[i - 1];
            sort(freq.begin(), freq.end());
            sort(nums.begin(), nums.end());
            long long ans = 0;
            for (int i = 0; i < n; i++)
                ans += (long long)freq[i] * nums[i];
            return ans % 1000000007;
        }
};
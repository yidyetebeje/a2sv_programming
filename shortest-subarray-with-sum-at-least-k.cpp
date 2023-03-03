class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            prefix[i + 1] = prefix[i] + (long long) nums[i];
        }
        int ans = INT32_MAX;
        deque<int> monoQ;
        for(int i = 0; i < prefix.size(); i++){
            while(!monoQ.empty() && prefix[i] <= prefix[monoQ.back()]){
                monoQ.pop_back();
            }
            while(!monoQ.empty() && prefix[i] >= prefix[monoQ.front()] + k){
                ans = min(ans, i - monoQ.front());
                monoQ.pop_front();
            }
            monoQ.push_back(i);
        }
        return ans == INT32_MAX ? -1 : ans;
    }
};
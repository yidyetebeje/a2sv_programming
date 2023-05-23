class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (int num : nums) {
            if (mp[num - 1].empty()) {
                mp[num].push(1);
            } else {
                int len = mp[num - 1].top();
                mp[num - 1].pop();
                mp[num].push(len + 1);
            }
        }
        for (auto& entry : mp) {
            if (!entry.second.empty() && entry.second.top() < 3) {
                return false;
            }
        }
        return true;
        }
};
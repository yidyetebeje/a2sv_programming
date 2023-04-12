class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        auto comp = [&mp](int n1, int n2) {
            return mp[n1] > mp[n2];
        };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for(pair<int,int> p: mp){
            heap.push(p.first);
            if(heap.size() > k) heap.pop();
        }
        vector<int> top(k);
        for (int i = k - 1; i >= 0; i--) {
            top[i] = heap.top();
            heap.pop();
        }
        return top;
    }
};
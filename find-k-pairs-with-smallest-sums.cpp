typedef tuple<int,int,int> t;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<t, vector<t>, greater<t>> pq;
        for(int i = 0; i < nums1.size(); i++){
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        vector<vector<int>> res;
        while(k-- && !pq.empty()){
            auto [a,b,c] = pq.top();
            pq.pop();
            res.push_back({nums1[b], nums2[c]});
            if(c < nums2.size() - 1) {
                pq.push({nums1[b] + nums2[c + 1], b, c + 1});
            }
        }
        return res;
    }
};
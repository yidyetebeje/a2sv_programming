class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        pair<int,int> ans = make_pair(0, 0);
        for(auto v: mp){
            if(ans.second < v.second){
                ans.first = v.first;
                ans.second = v.second;
            }
        }
        return ans.first;
    }
};
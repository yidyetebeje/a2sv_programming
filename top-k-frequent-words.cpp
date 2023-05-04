class Compare {
public:
    bool operator()(pair<int, string> below, pair<int, string> above)
    {
        if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }
 
        return false;
    }
};
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        priority_queue<pair<int,string>, vector<pair<int, string>>, Compare> pq;
        for(auto word: words) mp[word]++;
        for(auto pair: mp){
            pq.push(make_pair(pair.second, pair.first));
        }
        vector<string> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
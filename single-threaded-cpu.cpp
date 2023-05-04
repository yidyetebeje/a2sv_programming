class Solution {
public:
    vector<int> res;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> valid;
        for(int i=0; i<tasks.size(); i++){
            pq.push({tasks[i][0], tasks[i][1], i});
        }
        long long timestamp = pq.top()[0];
        while(!pq.empty() || !valid.empty()){
            while(!pq.empty() && timestamp>=pq.top()[0]){
                auto curr = pq.top();
                pq.pop();
                valid.push({curr[1], curr[2]});
            }
            if(valid.empty()){
                timestamp = pq.top()[0];
                continue;
            }
            auto validTop = valid.top();
            valid.pop();
            res.push_back(validTop[1]);
            timestamp+=validTop[0];
        }
        
        return res;

    }
};
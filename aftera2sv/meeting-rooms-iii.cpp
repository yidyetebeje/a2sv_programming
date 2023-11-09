class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        map<int,int> mp;
        priority_queue<int, vector<int>, greater<int>> assign;
       
        for(int i = 0; i < n;i++){
            assign.push(i);
        }
        for(int i = 0; i < meetings.size(); i++){
            while(!pq.empty() && pq.top().first <= meetings[i][0]){
                assign.push(pq.top().second);
                pq.pop();
            }
            if(pq.size() == n){
                auto tp = pq.top();
                pq.pop();
                tp.first = tp.first + (meetings[i][1]-meetings[i][0]);
                pq.push(tp);
                mp[tp.second]++;
            } else  {
                mp[assign.top()]++;
                pq.push({meetings[i][1],assign.top()});
                assign.pop();
            }
        }
        pair<int,int> maxp{0,0};
        for(auto m:mp){
            if(m.second > maxp.second){
                maxp = make_pair(m.first, m.second);
            }
            if(m.second == maxp.second && m.second < maxp.second){
                maxp = make_pair(m.first, m.second);
            }
        }
       
        return maxp.first;
    }
};
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        deque<pair<int,int>> dq;
        for(int i = 0; i < tickets.size(); i++) dq.push_back(make_pair(tickets[i], i));
        int loop = tickets[k];
        int count = 0;
        for(int i = 0; i < loop; i++){
            while(!dq.empty()){
                auto val = dq.front();
                val.first--;
                dq.pop_front();
                count++;
                if(val.first > 0) dq.push_back(val);
                else if(val.first ==  0 && val.second == k) return count;
            }
        }
        return -1;
    }
};
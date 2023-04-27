class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        deque<int> dq;
        vector<bool> visited(rooms.size());
        dq.push_back(0);
        visited[0] = true;
        while(!dq.empty()){
            auto v = rooms[dq.front()];
            dq.pop_front();
            for(auto x: v){
                if(!visited[x]){
                    visited[x] = true;
                    dq.push_back(x);
                }
            }
        }
        for(auto v: visited){
            if(!v) return false;
        } 
        return true;
    }
};
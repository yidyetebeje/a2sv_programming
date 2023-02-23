class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> passenger(1002);
        for(auto trip: trips){
            passenger[trip[1]] += trip[0];
            passenger[trip[2]] -= trip[0];
        }
        for(int i = 1; i < 1002; i++){
            passenger[i] += passenger[i - 1];
        }
        for(int i = 0; i < 1002; i++){
            if(passenger[i] > capacity) return false;
        }
        return true;
    }
};
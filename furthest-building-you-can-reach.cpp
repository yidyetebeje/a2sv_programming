class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i;
        for(i = 0; i < heights.size() - 1; i++){
            int h = heights[i + 1] - heights[i];
            if(h <= 0) continue;
            if(bricks - h >= 0){
                bricks -= h;
                pq.push(h);
            } else if(ladders > 0){
                if(!pq.empty() && h < pq.top()) {
                    bricks += pq.top();
                    pq.pop();
                    bricks -= h;
                    pq.push(h);
                }
                ladders--;
            } else break;
        }
        return i;
    }
};
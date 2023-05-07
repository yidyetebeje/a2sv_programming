class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        while(k--){
            int x = ceil((double)pq.top()/(double)2);
            pq.pop();
            pq.push(x);
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
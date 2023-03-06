class Solution {
public:
    long long timeTaken(vector<int>& piles, int mid){
        long long sum = 0;
        for(auto& v: piles) sum += ceil(double(v)/mid);
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = *max_element(piles.begin(), piles.end());
        while(r - l > 1){
            int m = l + (r - l)/2;
            if(timeTaken(piles, m) <= h){
                r = m;
            } else l = m;
        }
        return r;
    }
};
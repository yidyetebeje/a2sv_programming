class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end()) - 1;
        int r = accumulate(begin(weights), end(weights),0);
        while(r - l > 1){
            int m = l + (r - l)/2;
            if(!check(weights,days,m)){
                l = m;
            } else r = m;
        }
        return r;
    }
    bool check(vector<int>& weights, int days, int capacity){
        int requiredDays = 1;
        int currWeight = 0;
        for(int i : weights){
            if(currWeight + i > capacity){
                requiredDays++;
                currWeight = 0;
            }
            currWeight += i;
        }
        if(requiredDays > days) return false;
        return true;
    }

};
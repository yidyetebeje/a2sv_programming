class Solution {
public:
    int minF = INT32_MAX;
    int k = 0;
    void backTrack(vector<int>& cookies,int i, vector<int>& count){
        if(i >= cookies.size()){
            minF = min(minF, *max_element(count.begin(), count.end()));
            return;
        }
        if(*max_element(count.begin(), count.end()) > minF) return;
        for(auto j = 0; j < k; j++){
            count[j] += cookies[i];
            backTrack(cookies, i+1, count);
            count[j] -= cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        this->k = k;
        vector<int> bucket(k);
        backTrack(cookies, 0, bucket);
        return minF;
    }
};
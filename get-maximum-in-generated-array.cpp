class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> dp(n +1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            if(i % 2 == 0){
                int k = i / 2;
                
                dp[i] = dp[k];
            }
            else {
                int k = (i - 1)/ 2;
                
                dp[i] = dp[k] + dp[k +  1];
            } 
        }
        return *max_element(dp.begin(), dp.end());
    }
};
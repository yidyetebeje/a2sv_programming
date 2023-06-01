class Solution {
public:
    int dp[21][1001];
    int solve(int n, int sum, vector<int>&a){
        if(n==0){
            if(sum==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(sum<0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        return dp[n][sum] = solve(n-1,sum-a[n-1],a) + solve(n-1,sum,a);
    }
    int findTargetSumWays(vector<int>& a, int target) {
        
        memset(dp,-1,sizeof(dp));
        if(target<0){
            target*=-1;
        }
        int sum = 0 ;
        for(int &x:a){
            sum+=x;
        }
        if((sum+target)%2==1){
            return 0;
        }
        int req = (sum-target)/2;
        return solve(a.size(),req,a);

    }
};
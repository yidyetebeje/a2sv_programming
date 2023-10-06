class Solution {
public: 
    int dp[100001][2];
    int findans(vector<int>&a,vector<int>&b,int i,int val)
    {
        if(i==0)
            return 0;
        if(dp[i][val]!=-1)
            return dp[i][val];
        int ans=INT_MAX-1;        
        if(val==1)
        {
            if(a[i]>b[i-1] && b[i]>a[i-1])
            {
                ans=min(ans,findans(a,b,i-1,0));
            }
            if(a[i]>a[i-1] && b[i]>b[i-1])
            {
                ans=min(ans,1+findans(a,b,i-1,1));
            }
        }
        else
        {

            if(a[i]>a[i-1] && b[i]>b[i-1])
            {
                ans=min(ans,findans(a,b,i-1,0));
            }
             if(a[i]>b[i-1] && b[i]>a[i-1])
            {
                ans=min(ans,1+findans(a,b,i-1,1));
            }
        }
        return dp[i][val]=ans;
    }
    int minSwap(vector<int>& a, vector<int>& b) {
        memset(dp,-1,sizeof(dp));
        int n=a.size();
        return min(findans(a,b,n-1,0),1+findans(a,b,n-1,1));
    }
};
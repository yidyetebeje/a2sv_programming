class Solution {
public:
    string subStrHash(string s, int p, int mod, int k, int h) {
        int n = s.length();
        int cur = 0;
        vector<int>P(k + 1,0);
        int index = -1;
        P[0] = 1;
        for(int i = 1; i <= k; i++)//storing the powers
        {
            P[i] = (1ll*P[i - 1] * p)  % mod;
        }
        for(int i =  n - k; i < n; i++)// we have to start from the end as we will multiply with p not divide
        {
            cur += (1ll*(s[i] - 'a' + 1) * P[i - (n - k)]) % mod;
            cur = cur % mod;
        }
        
        for(int i = n - k - 1; i >= 0; i--)
        {
            if(cur == h)
            {
                index = i + 1;//we have to get the first from the beginning
            }
            cur =   (1ll* cur * p) % mod;
            cur = (cur + (s[i] - 'a' + 1)) % mod ;
            int temp = (1ll*(s[i + k] - 'a' + 1) * P[k]) % mod;
            cur = (cur - temp + mod) % mod;
            
        }
        if(cur == h)
        {
           return s.substr(0,k);
        }
        return s.substr(index,k);
        
        
        
    }
};
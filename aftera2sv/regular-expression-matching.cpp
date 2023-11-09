
class Solution {
public:
    bool recursive(string &s,string& p, int i, int j, vector<unordered_map<int,bool>> &dp){
        
        if((i < 0 && j < 0)){
            return true;
        }
        if(i < 0 && j > 0 && p[j] == '*'){
            for(int k = j; k >= 0; k-=2){
                if(p[k] != '*') return false;
            }
            return true;
        }   
        
        if((i < 0 || j < 0) || (j < 0 && i >= 0)){
            return false;
        }
        if(dp[i].count(j)){
            return dp[i][j];
        }
        if(p[j] == '.'){
            return dp[i][j] = recursive(s,p, i - 1, j - 1, dp);
        }
        if(p[j] == '*'){
            if(s[i] == p[j - 1] || p[j - 1] == '.'){
                return dp[i][j] = (recursive(s,p, i - 1, j, dp) || recursive(s,p, i, j - 2, dp));
            } else {
                cout << i << " " <<  j << endl;
                return dp[i][j] = recursive(s,p, i, j - 2, dp);
            }
        }
        if(s[i] == p[j]){
            return dp[i][j] = recursive(s,p,i-1,j-1, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<unordered_map<int,bool>> dp(s.size());
        return recursive(s, p, s.size() - 1, p.size() -1 , dp);
    }
};
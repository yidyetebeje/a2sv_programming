class Solution {
public:
    int balancedString(string s) {
        unordered_map<int,int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        int l = 0;
        int res = s.size();
        int n = s.size()/4;
        for(int r = 0; r < s.size(); ++r){
            mp[s[r]]--;
            while(l < s.size() && mp['W'] <= n && mp['Q'] <= n && mp['E'] <= n && mp['R'] <= n){
                res = min(res, r - l + 1);
                mp[s[l]]++;
                l++;
            }
        }
        return res;
    }
};
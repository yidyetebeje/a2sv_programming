class Solution {
public:
    string minWindow(string &s, string &t) {
        int ns = s.size();
        int nt = t.size();
        vector<int> mp(128, 0);
        for(auto i: t) mp[i]++;
        int i = 0, j = 0,min = INT32_MAX, start = 0, required = t.size();
        while(i <= s.size() &&  j <= s.size()){
            if(required){
                if(i == s.size()) break;
                mp[s[i]]--;
                if(mp[s[i]] >= 0) required--;
                i++;
            } else {
                 if(i-j < min){
                    min = i-j;
                    start = j;                    
                }
                mp[s[j]]++;
                if(mp[s[j]]>0)
                    required++; 
                j++; 
            }
        }
        return min == INT32_MAX ? "" : s.substr(start, min);
    }
};
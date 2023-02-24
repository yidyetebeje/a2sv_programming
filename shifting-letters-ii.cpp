class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefix(s.size() + 1);
        for(auto shift:shifts){
            int dir = shift[2];
            if(dir == 1){
                prefix[shift[0]] += 1;
                prefix[shift[1] + 1] -= 1;
            } else {
                prefix[shift[0]] -= 1;
                prefix[shift[1] + 1] += 1;
            }
        }
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] += prefix[i - 1];
        }
        for(int i = 0; i < s.size(); i++){
            int mod = prefix[i] % 26;
            mod = mod >= 0 ? mod : 26 + mod;
            s[i] = ((s[i] - 'a' + mod) % 26) + 97 ;
        }
        return s;
    }
};
class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    int repeatedStringMatch(string a, string b) {
        int j = 0;
        vector<int> prefix = prefix_function(b);
        int maxEl = 3 * (max(a.size(), b.size())/min(a.size(), b.size()));
        for(int k = 1; k <= maxEl; k++){
            for(int i = 0; i < a.size(); i++){
               
                if(j == b.size()) return k;
                if(a[i] == b[j]){
                    j++;
                } 
                else if(j == 0) j = 0;
                else {

                    j = prefix[j - 1];
                    i -= 1;
                }
                
            }
            if(j == b.size()) return k;
        }
        if(j == b.size()) return 0;
        return -1;
    }
};
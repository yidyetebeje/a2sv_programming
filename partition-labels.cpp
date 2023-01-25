class Solution {
public:
    vector<int> partitionLabels(string s){
        vector<int> lastIndex(26,0);
        for(int i = 0; i < s.size(); i++){
            lastIndex[s[i] - 'a'] = i;
        }
        int r = 0;
        int l = 0;
        vector<int> res;
        for(int i = 0; i < s.size(); i++){
            r = max(r, lastIndex[s[i] - 'a']);
            if(i == r){
                res.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return res;
    }

};
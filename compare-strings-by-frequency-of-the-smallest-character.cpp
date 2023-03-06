class Solution {
public:
    int minChar(string& s){
        sort(s.begin(), s.end());
        int index = upper_bound(s.begin(), s.end(), s[0]) - s.begin();
        return index;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> count;
        vector<int> res;
        for(auto word: words) count.push_back(minChar(word));
        sort(count.begin(), count.end());
        for(auto query: queries){
            int minC = minChar(query);
            int index = upper_bound(count.begin(), count.end(),minC) - count.begin();
            res.push_back(count.size() - index);
        }
        return res;
    }
};
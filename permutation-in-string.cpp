class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> ms1;
        unordered_map<char, int> ms2;
        if(s1.size() > s2.size()) return false;
        for(int i = 0; i < s1.size(); i++){
            ms1[s1[i]]++, ms2[s2[i]]++;
        }
        int l = 0, r = s1.size();
        while(r < s2.size()){
            if(ms1 == ms2) return true;
            ms2[s2[r]]++;
            ms2[s2[l]]--;
            if(ms2[s2[l]] == 0) ms2.erase(s2[l]);
            r++, l++;
        }
        if(ms1 == ms2) return true;
        return false;
    }
};
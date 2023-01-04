class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> dict;
        unordered_map<char, char> dict2;
        for(int i = 0; i < s.size(); i++){
            if(dict.find(s[i]) == dict.end() && dict2.find(t[i]) == dict.end()){
                dict[s[i]] = t[i];
                dict2[t[i]] = s[i];
            } else if(dict[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};
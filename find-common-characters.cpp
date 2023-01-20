class Solution {
public:
    string findCommon(string w, string s){
        string r;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(auto l: w){
            mp1[l]++;
        }
        for(auto l: s) mp2[l]++;
        for(auto pi: mp1){
            if(mp2.find(pi.first) != mp2.end()){
                int minI = min(pi.second, mp2[pi.first]);
                for(int i = 0; i < minI; i++){
                    r += pi.first;
                }
            }
        }
        return r;
    }
    vector<string> commonChars(vector<string>& words) {
        string s = findCommon(words[0], words[1]);
        for(int i = 2; i < words.size(); i++){
            s = findCommon(s, words[i]);
        }
        vector<string> v;
        for(auto l : s) {
            string k;
            k += l;
            v.push_back(k);
        }
        return v;
    }
};
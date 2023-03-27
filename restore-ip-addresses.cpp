class Solution {
public:
    vector<string> vec;
    string changeToIp(vector<string>& vi){
        string ch;
        for(int i = 0; i < vi.size(); i++){
            if(i != vi.size() - 1)
                ch += (vi[i] + ".");
            else ch += vi[i];
        }
        return ch;
    }
    void backTrack(string& s, vector<string>& v, int start){
        if (v.size() == 4){
            string y = changeToIp(v);
            if(y.size() == s.size() + 3)
                vec.push_back(y);
            return;
        }
        for(int i = 1; i <= 3; i++){
            if(start + i <= s.size()){
                string x = s.substr(start, i);
                if(stoi(x) <= 255 && (x.size() <= 1 || x[0] != '0') ){
                    v.push_back(x);
                    backTrack(s, v, start + i);
                    v.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        backTrack(s, v, 0);
        return vec;
    }
};
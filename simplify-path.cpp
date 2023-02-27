class Solution {
public:
    vector<string> split(string& s){
        vector<string> p;
        string x = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '/' && x.size() != 0){
                p.push_back(x);
                x = "";
            }
            else if(s[i] != '/') x += s[i];
        }
        if(x.size() != 0) p.push_back(x);
        return p;
    }
    string simplifyPath(string path) {
        vector<string> paths = split(path);
        vector<string> st;
        for(auto v: paths){
            if(v != ".." && v != ".") st.push_back(v);
            else if(v == ".." && !st.empty()) st.pop_back();
        }
        string output = "";
        if(st.empty()) return "/";
        for(auto v: st){
            output += '/' + v;
        }
        return output;
    }
};
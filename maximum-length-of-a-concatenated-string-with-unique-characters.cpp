class Solution {
public:
    int ans = 0;
    bool valid(string& s){
        unordered_set<char> st;
        for(auto c: s){
            if(st.find(c) == st.end()) st.insert(c);
            else return false;
        }
        return true;
    }
    void backTrack(vector<string>& arr, int start, string& s){
        int n = s.size();
        ans = max(ans, n);
        for(int i = start; i < arr.size(); i++){
            string p = s + arr[i];
            if(valid(p)){
                backTrack(arr, i + 1, p);
                p = s;
            }
        }
    }
    int maxLength(vector<string>& arr) {
        string s;
        backTrack(arr, 0, s);
        return ans;
    }
};
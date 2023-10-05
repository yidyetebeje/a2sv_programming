class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(auto c: s) {
            if(st.empty()){
                st.push({c, 1});
            } else {
                auto t = st.top();
                if(t.first == c){
                    st.pop();
                    if(t.second + 1 != k){
                        st.push({c, t.second + 1});
                    }
                } else {
                    st.push({c, 1});
                }
            }
        }
        string y = "";
        while(!st.empty()){
            int temp = st.top().second;
            while(temp--){
                y += st.top().first;
            }
            st.pop();
        }
        reverse(y.begin(),y.end());
        return y;
    }
};
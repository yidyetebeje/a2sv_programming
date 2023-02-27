class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        int nm = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') {
                string k = "";
                k += s[i];
                st.push(k);
            }
            else if(s[i] == ')'){
                if(st.top() == "("){
                    st.pop();
                    st.push("1");
                } else {
                    int count = 0;
                    while(st.top() != "("){
                        count += stoi(st.top());
                        st.pop();
                    }
                    st.pop();
                    st.push(to_string(2 * count));
                }
            }
        }   
        while(!st.empty()){
            res += stoi(st.top());
            st.pop();
        }
        return res;
    }
};
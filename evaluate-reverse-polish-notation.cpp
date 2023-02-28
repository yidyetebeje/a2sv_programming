class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long int> st;
        for(string & i : tokens){
            if(i == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if(i == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if(i == "*"){
                long int a = st.top();
                st.pop();
                long int b = st.top();
                st.pop();
                st.push(a * b);
            }
            else if(i == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};
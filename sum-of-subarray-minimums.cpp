class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<long long, long long>> st;
        long long res = 0;

        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && st.top().first > arr[i]){
                auto pr = st.top();
                st.pop();
                if(!st.empty()){
                    res = (res + (pr.first)*(i - pr.second)*(pr.second - st.top().second));
                } else {
                     res = ( res +(pr.first)*(i - pr.second)*(pr.second + 1));
                }
            }
            st.push(make_pair(arr[i], i));
        }
        int i = arr.size();
        while(!st.empty()){
                auto pr = st.top();
                st.pop();
                if(!st.empty()){
                    res = (res + (pr.first)*(i - pr.second)*(pr.second - st.top().second)) ;
                } else {
                     res = ( res +(pr.first)*(i - pr.second)*(pr.second + 1));
                }
        }
        return res%1000000007 ;
    }
};
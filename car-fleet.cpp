class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pre;
        for(int i = 0; i < position.size(); i++){
            pre.push_back(make_pair(position[i], speed[i]));
        }
        sort(pre.begin(), pre.end(), [](auto a, auto b){
            return a.first > b.first;
        });
        int count = 0;
        stack<double> st;
        for(int i = pre.size() - 1; i >= 0; i--){
            double time = (double)(target - pre[i].first)/pre[i].second;
            while(!st.empty() && st.top() <= time){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};
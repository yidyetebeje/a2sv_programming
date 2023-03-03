class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> vt(nums.size(), -1);
        for(int i = 0; i < 2*nums.size() - 1; i++){
            int key = i % nums.size();
            while(!st.empty() && nums[st.top()] < nums[key]){
                vt[st.top()] = nums[key];
                st.pop();
            }
            if(vt[key] == -1)
                st.push(key);
        } 
        while(!st.empty()){
            vt[st.top()] = -1;
            st.pop();
        }
        return vt;
    }
};
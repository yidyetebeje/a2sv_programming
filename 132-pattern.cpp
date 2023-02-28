class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int k = INT32_MIN;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < k) return true;
            while(!st.empty() && st.top() < nums[i]){
                k = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
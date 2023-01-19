class Solution {



public:
    vector<int> pancakeSort(vector<int>& arr) {
        
        vector < int > ans;
        int n = arr.size();

        while ( arr.size() ) {
            n = arr.size();
            int maxIdx = max_element(arr.begin(), arr.end()) - arr.begin();
            reverse(arr.begin(), arr.begin() + maxIdx + 1);
            ans.push_back(maxIdx + 1);
            reverse(arr.begin(), arr.end());
            ans.push_back(n);
            arr.pop_back();
        }

        return ans;

    }
};
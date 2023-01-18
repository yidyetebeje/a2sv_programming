class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int& i, int& j){
            string first = to_string(i);
            string second = to_string(j);
            return first + second > second + first;
        });
        string s;
        for(auto i: nums){
            s += to_string(i);
        }
        return (s[0] == '0' ? "0" : s);
    }
};
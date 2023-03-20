class Solution {
public:
    int n = 0;
    int k = 0;
    vector<vector<int>> combinations;
    void backTrack(int i, vector<int>& combination){
        if(combination.size() == k){
            combinations.push_back(combination);
            return;
        }
        if(i > n) return;
        combination.push_back(i);
        backTrack(i +  1, combination);
        combination.pop_back();
        backTrack(i + 1, combination);
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> v;
        backTrack(1,v );
        return combinations;
    }
};
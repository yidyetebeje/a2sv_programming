class Solution {
public:
    vector<int> res;
    vector<pair<int,int>> mergeSort(vector<pair<int,int>>& nums, int l, int r){
        if(l == r) {
            
            return vector<pair<int,int>>{nums[l]};
        }
        int mid = l + (r - l)/2;
        auto left = mergeSort(nums, l, mid);
        auto right = mergeSort(nums, mid + 1, r); 
        return merge(left, right);
    }
    vector<pair<int,int>> merge(vector<pair<int,int>>& left, vector<pair<int,int>>& right){
        vector<pair<int, int>> merged(left.size() + right.size());
        int n = left.size();
        int m = right.size();
        int i = 0, j = 0, k = 0;
        int count = 0;
        while(i < n && j < m){
            if(left[i] < right[j]){
                merged[k] = left[i];
                res[left[i].second] += count;
                i++; 
            } else if(right[j] <= left[i]){
                merged[k] = right[j];
                count++;
                j++;
            }
            k++;
        }
        while(i < n){
            res[left[i].second] += count;
            merged[k++] = (left[i++]);
        }
        while(j < m) merged[k++] = (right[j++]);
        return merged;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> nm;
        res.resize(nums.size());
        for(int i = 0; i < nums.size(); i++){
            nm.push_back(make_pair(nums[i], i));
        }   
        auto v = mergeSort(nm, 0, nm.size() - 1);
        return res;
    }
};
class Solution {
public:
    int d;
    long long Merge(vector <pair<int,int>> & nums, int low, int mid, int high) {
        long long total = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (nums[i].first - nums[i].second) <= (nums[j].first - nums[j].second + d)) {
                j++;
            }
            total += (j - (mid + 1));
        }
        vector < pair<int,int> > t;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {

            if ((nums[left].first - nums[left].second)  > (nums[right].first - nums[right].second)) {
                t.push_back(nums[left++]);
            } else {
                t.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            t.push_back(nums[left++]);
        }
        while (right <= high) {
            t.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = t[i - low];
        }
        return total;
}
    long long MergeSort(vector < pair<int,int>> & nums, int low, int high) {

        if (low >= high) return 0;
        int mid = (low + high) / 2;
        long long inv = MergeSort(nums, low, mid);
        inv += MergeSort(nums, mid + 1, high);
        inv += Merge(nums, low, mid, high);
        return inv;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<pair<int,int>> arr(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            arr[i] = make_pair(nums1[i], nums2[i]);
        }
        
        d = diff;
        long long n = MergeSort(arr, 0, arr.size() - 1);
        for(auto v: arr) {
            cout << v.first << " " << v.second << endl;
        }
        return n;
    }
};
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int min = 0, max = citations.size() + 1;
        int mid;

        while (max - min > 1) {
            mid = (min + max) / 2;
            if (isH(mid, citations)) {
                min = mid;
            } else {
                max = mid;
            }
        }
        return min;
    }

    bool isH(int h, vector<int>& citations) {
        int index = lower_bound(citations.begin(), citations.end(), h) - citations.begin();
        int n = citations.size();
        if(n - index < h) return false;
        return true;
    }
};
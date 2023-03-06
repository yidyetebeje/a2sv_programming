class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l <= r){
            int mid = l + (r - l)/2;
            long long res = (long long)mid*mid;
            if(res == x) return mid;
            else if(res < x) l = mid + 1;
            else r = mid - 1;
        }
        return l - 1;
    }
};
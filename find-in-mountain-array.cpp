/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int sz = mountainArr.length();
        int l = 0, r = sz;
         int ans = 0;
        while(r - l > 1){
            int mid = l + (r - l)/2;
            int val = mountainArr.get(mid);
            int prev = mountainArr.get(mid - 1);
            int next = mountainArr.get(mid + 1);
            if(prev <= val && val <= next){
                l = mid;
            } else if(prev >= val && next <= val) {
                r = mid;
            } else {
                ans = mid;
                break;
            }
        }
        l = -1; r = ans;
        while(r - l > 1){
            int mid = l + (r - l)/2;
            int val = mountainArr.get(mid);
            if(val >= target){
                r = mid;
            } else {
                l = mid;
            }
        }
        int val = mountainArr.get(r);
        if(r < sz && val == target){
            return r;
        }
        l = ans - 1; r = sz;
        while(r - l > 1){
            int mid = l + (r - l)/2;
            int val = mountainArr.get(mid);
            if(val <= target){
                r = mid;
            } else {
                l = mid;
            }
        }
       
        if(r < sz){
            val = mountainArr.get(r);
            if(val == target) return r;
        }
        return -1;
    }
};
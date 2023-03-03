class Solution {
public:
    bool isTrue(double n){
        if(n == 1) return true;
        if(n < 1) return false;
        return isTrue(n/4);
    }
    bool isPowerOfFour(int n) {
        return isTrue(n);
    }
};
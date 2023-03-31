class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = 32 - __builtin_clz(n);
        auto prevbit = (n >> 0) & 1;
        for(int i = 1; i <= x;i++){
            auto curbit = (n >> i) & 1;
            if(prevbit == curbit) return false;
            prevbit = curbit;
        }
        return true;
    }
};
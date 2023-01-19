class Solution {
public:
    int secondLargest(int a, int b, int c){
        if((a >= b && a <= c) || (a >= c && a <= b)){
            return a;
        } else if ((b >= a && b <= c) || (b >= c && b <= a)){
            return b;
        } else {
            return c;
        }
    }
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int left = 0, right = piles.size() - 1;
        int count = 0;
        while(left < right){
            int smax = secondLargest(piles[left], piles[right], piles[right - 1]);
            count += smax;
            left++;
            right -= 2;
        }
        return count;
    }
};
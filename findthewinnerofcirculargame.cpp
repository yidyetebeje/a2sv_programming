class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n, 0);
        for(int i = 1; i <= n; i++){
            v[i - 1] = i;
        }
        int i = 0;
        while(v.size() != 1){
            i = (i + k - 1) % n;
            v.erase(v.begin() + i);
            n--;
        }
        return v[0];
    }
};
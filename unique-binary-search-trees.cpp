class Solution {
public:
    // the function depend only on since the bst doesn't care about the element we have it only care about the number of element we have give us unique subtree
    vector<int> dp;
    int recursive(int n){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += (recursive(i - 1) * recursive(n - i)); // left only i -1 and the right only n - i s
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        dp = vector<int>(n + 1, -1);
        return recursive(n);
    }
};
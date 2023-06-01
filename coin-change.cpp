class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount + 1, INT_MAX - 1);
        count[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin: coins){
                if(i - coin >= 0){
                    count[i] = min(count[i],1 + count[i - coin]);
                }
            }
        }
        return count[amount] == INT_MAX - 1? -1: count[amount];
    }

};
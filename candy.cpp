class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n, i = 1;
        while(i < n){
            if(ratings[i] == ratings[i - 1]){
                i++;
                continue;
            }
            int up = 0;
            while(ratings[i] > ratings[i - 1]){
                up++;
                candy += up;
                i++;
                if(i == n) return candy;
            }
            int down = 0;
            while(i < n &&  ratings[i] < ratings[i - 1]){
                down++;
                candy += down;
                i++;
            }
            candy -= min(up,down);
        }
        return candy;
    }
};
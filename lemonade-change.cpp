class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;
        for(auto el: bills){
            if(el == 5){
                mp[el]++;
            } else if(el == 10){
                if(mp[5] > 0){
                    mp[5]--;
                    mp[el]++;
                } else return false;
            } else{
                if(mp[10] > 0 && mp[5] > 0){
                    mp[10]--;
                    mp[5]--;
                } else if(mp[5] > 2){
                    mp[5]-=3;
                } else return false;
            }
        }
        return true;
    }
};
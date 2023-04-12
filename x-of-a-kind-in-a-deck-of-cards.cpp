class Solution {
public:
    bool isDivisible(int n, int target){
        for(int i = 0; i <= n/target; i++){
            if(n * i == target) return true;
        }
        return false;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for(auto d: deck){
            mp[d]++;
        }
        int m = mp[deck[0]];
        
        for(auto v: mp){
            m = gcd(m, v.second);
        }
        if(m == 1) return false;
        return true;
    }
};
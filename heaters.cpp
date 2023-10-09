class Solution {
public:
    bool good(vector<int>& houses, vector<int>& heaters, int radius){
        int j = 0;
        for(int i = 0; i < houses.size(); i++){
            while(j < heaters.size() && abs(houses[i] - heaters[j]) > radius){
                j++;
            }
        }
        if(j >= heaters.size()) return false; 
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = -1, r = 823564440;
        while(r - l > 1){
            int mid = l + (r - l) / 2;
            if(good(houses, heaters, mid)){
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
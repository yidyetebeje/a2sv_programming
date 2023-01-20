class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int turns = 1;
        if(arr.size() <= 2){
            return false;
        }
        bool inc = (arr[0] < arr[1]);
        if(!inc) return false;
        int r = 1;
        while(r < arr.size()){
            if(arr[r] > arr[r - 1]){
                r++;
            } else break;
        }
        if(r == arr.size()) return false;
        while(r < arr.size()){
            if(arr[r] < arr[r - 1]){
                r++;
            } else return false;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() -1;
        vector<int> vi(2);
        while(l < r){
            int sum = numbers[l] + numbers[r];
            if(sum < target){
                l++;
            } else if(sum > target){
                r--;
            }  
            else {
                vi[0] = l + 1;
                vi[1] = r + 1;
                return vi;
            }
        } 
        return vi;  
    }
};
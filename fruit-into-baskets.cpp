class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         int curMax = 0, maxLen = 0;
    int left = 0, right = 0;
    vector<int> curFruits;
    for (int i = 0; i < fruits.size(); i++){
        if(find(curFruits.begin(), curFruits.end(), fruits[i]) == curFruits.end()){
            if(curFruits.size() == 2){
                maxLen = maxLen > curMax ? maxLen : curMax;
                while(find(curFruits.begin(), curFruits.end(), fruits[left]) == curFruits.end()){
                    left++;
                }
                curFruits.erase(find(curFruits.begin(), curFruits.end(), fruits[left]));
                left++;
            }
            curFruits.push_back(fruits[i]);
        }
        right++;
        curMax = right - left;
    }
    return maxLen > (right - left) ? maxLen : (right - left);
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            return vector<int>{1};
        }
        vector<int> res = getRow(rowIndex - 1);
        vector<int> ans(rowIndex + 1);
        for(int i = 0; i < rowIndex + 1;i++){
                if(i == 0) ans[i] = 1;
                else if(i == rowIndex) ans[i] = 1;
                else{
                     ans[i] = res[i - 1] + res[i];
                } 
                   
        }
        return ans;
    }
};
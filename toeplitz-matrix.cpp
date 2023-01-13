class Solution {
public:
    bool isValid(int i, int j, int col,int row){
        if(i >= row || j >= col){
            return false;
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rsize = matrix.size();
        int csize = matrix[0].size();
        int maxSize = max(rsize, csize);
        for(int j = 0; j < maxSize; j++){
            for(int i = 1; i < maxSize; i++){
                if(isValid(i + j, i, csize, rsize)){
                    if(matrix[i + j][i] != matrix[i + j - 1][i - 1]){
                        return false;
                    }
                }else{
                    break;
                }
            }
        }
        for(int j = 0; j < maxSize; j++){
            for(int i = 1; i < maxSize; i++){
                if(isValid(i, i + j, csize, rsize)){
                    if(matrix[i][j + i] != matrix[i - 1][i + j - 1]){
                        return false;
                    }
                }else{
                    break;
                }
            }
        }
        return true;
    }
};
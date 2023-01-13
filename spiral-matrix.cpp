class Solution {
public:
    void traverse(int c, int r, int colSize, int rowSize, vector<int>& linear, const vector<vector<int>>&  matrix){
        if (colSize <= c || rowSize <= r){
            return;
        }
        for(int i = c; (i < colSize); i++){
            linear.push_back(matrix[r][i]);
        }
        r = r + 1;
        for(int i = r; i < rowSize; i++){
            linear.push_back(matrix[i][colSize - 1]);
        }
        colSize--;
        if (!(colSize > c && rowSize > r)){
            return;
        }
        for(int i = colSize - 1; i >= c; i--){
            linear.push_back(matrix[rowSize - 1][i]);
        }
        rowSize--;
        for(int i = rowSize - 1; i >= r; i--){
            linear.push_back(matrix[i][c]);
        }
        c++;
        
        traverse(c, r, colSize, rowSize, linear, matrix);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rsize = matrix.size();
        int csize = matrix[0].size();
        vector<int> linear;
        linear.reserve(rsize * csize);
        traverse(0,0,csize, rsize, linear, matrix);
        return linear;
    }
};
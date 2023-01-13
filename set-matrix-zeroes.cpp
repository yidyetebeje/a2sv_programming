class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> col;
        unordered_set<int> row;
        int rsize = matrix.size();
        int csize = matrix[0].size();
        for(int i = 0; i < rsize; i++){
            for(int j = 0; j < csize; j++){
                if(matrix[i][j] == 0){
                    col.insert(j);
                    row.insert(i);
                }
            }
        }
        for(auto c: col){
            for(int i = 0; i < rsize; i++){
                matrix[i][c] = 0;
            }
        }   
        for(auto r: row){
            for(int i = 0; i < csize; i++){
                matrix[r][i] = 0;
            }
        }   
    }
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        if(row*col != r * c) return mat;
        vector<vector<int>> v(r, vector<int>(c, 0));
        int k = 0;
        int m = 0;
       
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                v[k][m++] = mat[i][j];
                if(m == c){
                    m = 0;
                    k++;
                }
                cout << k << endl;
            }
        }
        return v;
    }
};
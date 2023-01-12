class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int colSize = matrix[0].size();
        int rowSize = matrix.size();
        int dim = (rowSize - 1) * colSize + (colSize - 1);
        int l = 0, r = dim;
        while(l <= r){
            int m = l + (r - l)/2;
            int cr = m / colSize;
            int cl = m % colSize;
            if(matrix[cr][cl] == target){
                return true;
            } else if(matrix[cr][cl] > target){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};
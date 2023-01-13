class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rsize = board.size();
        int csize = board[0].size();

        //check for row
        for(int i = 0; i < rsize; i++){
            unordered_set<int> mySet;
            for(int j = 0; j < csize; j++){
                 if(board[i][j] == '.') continue;
                if(mySet.find(board[i][j]) != mySet.end()){
                    return false;
                }
                mySet.insert(board[i][j]);
            }
        }
         //check for col
        for(int i = 0; i < csize; i++){
            unordered_set<int> mySet;
            for(int j = 0; j < rsize; j++){
                if(board[j][i] == '.') continue;
                if(mySet.find(board[j][i]) != mySet.end()){
                    return false;
                }
                mySet.insert(board[j][i]);
            }
        }
        //check for 3x3 board
        int c = 0, r = 0;
        while(true){
            if(c == 9){
                r += 3;
                c = 0;
            }
            if(r == 9) break;
            unordered_set<int> mySet;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(board[i + r][j + c] == '.') continue;
                    if(mySet.find(board[i + r][j + c]) != mySet.end()){
                        return false;
                    }
                    mySet.insert(board[i + r][j + c]);
                }
            }
            c += 3;
        }
        return true;
    }
};
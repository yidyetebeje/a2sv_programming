class Solution {
public:
    void reveal(vector<vector<char>>& board, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'E') {
            return;
        }
        int mines = 0;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'M') {
                    mines++;
                }
            }
        }
        if (mines > 0) {
            board[row][col] = '0' + mines;
        } else {
            board[row][col] = 'B';
            for (int i = row - 1; i <= row + 1; i++) {
                for (int j = col - 1; j <= col + 1; j++) {
                    reveal(board, i, j);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
        } else {
            reveal(board, row, col);
        }
        return board;
    }
};
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];
        
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }
        else {
            reveal(board, row, col);
            return board;
        }
    }
    
    int getAdjacentMines(vector<vector<char>>& board, int row, int col) {
        int cnt = 0;
        for (int i = -1; i <= 1; i ++) {
            for (int j = -1; j <= 1; j ++) {
                if (row+i < 0 || row+i >= board.size() || col+j < 0 || col+j >= board[0].size()) continue;
                if (board[row+i][col+j] == 'M') cnt ++;
            }
        }
        return cnt;
    }
    
    void reveal(vector<vector<char>>& board, int row, int col) {
        int mines = getAdjacentMines(board, row, col);
        if (mines > 0) {
            char to_put = '0' + mines;
            board[row][col] = to_put;
            return;
        } 
        else {
            board[row][col] = 'B';
            for (int i = -1; i <= 1; i ++) {
                for (int j = -1; j <= 1; j ++) {
                    if (row+i < 0 || row+i >= board.size() || col+j < 0 || col+j >= board[0].size()) continue;
                    if (board[row+i][col+j] == 'E') reveal(board, row+i, col+j);
                }
            }
        } 
    }
};
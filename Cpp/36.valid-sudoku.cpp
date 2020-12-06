class Solution {
   public:
    bool isValidSudoku(vector<vector<char>> &board) {
        map<char, int> hm;
        for (char c = '1'; c <= '9'; c++) hm[c] = 0;

        // row
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                else {
                    if (hm[board[i][j]] == 1) return false;
                    hm[board[i][j]]++;
                }
            }
            for (auto &&[key, val] : hm) val = 0;
        }

        // column
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                else {
                    if (hm[board[i][j]] == 1) return false;
                    hm[board[i][j]]++;
                }
            }
            for (auto &&[key, val] : hm) val = 0;
        }

        // sub_board
        vector<vector<int>> start_cells{
            {0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (board[start_cells[i][0] + j][start_cells[i][1] + k] == '.')
                        continue;
                    else {
                        if (hm[board[start_cells[i][0] + j][start_cells[i][1] + k]] == 1) 
                            return false;
                        hm[board[start_cells[i][0] + j][start_cells[i][1] + k]]++;
                    }
                }
            }
            for (auto &&[key, val] : hm) val = 0;
        }
        return true;
    }
};
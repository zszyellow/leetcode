class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool sign = backtrace(board, 0, 0);
    }
    
    bool backtrace(vector<vector<char>>& board, int row, int col)
    {
        if(col == board[0].size())
        {
            row += 1;
            col = 0;
        }

        for (int i = row; i < 9; i ++)
        {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') continue;
                for (int k = 1; k <= 9; k ++)
                {
                    board[i][j] = (char)('0' + k);
                    if (isValidSuduku(board) && backtrace(board, i, j + 1)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
    
    bool isValidSuduku(vector<vector<char>>& board) {
        map<char, int> m{
            {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0}
        };
        
        // row
        for (int i = 0; i < 9; i ++)
        {
            for (int j = 0; j < 9; j ++)
            {
                if (board[i][j] == '.') continue;
                else 
                {
                    if (m[board[i][j]] == 1) return false;
                    m[board[i][j]] ++;
                }
            }
            for (auto it = m.begin(); it != m.end(); it ++) it->second = 0;
        }
        
        // column
        for (int j = 0; j < 9; j ++)
        {
            for (int i = 0; i < 9; i ++)
            {
                if (board[i][j] == '.') continue;
                else 
                {
                    if (m[board[i][j]] == 1) return false;
                    m[board[i][j]] ++;
                }
            }
            for (auto it = m.begin(); it != m.end(); it ++) it->second = 0;
        }
        
        // small pieces
        vector<vector<int>> firstCell{
            {0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}
        };
        for (int i = 0; i < 9; i ++)
        {
            for (int j = 0; j < 3; j ++)
            {
                for (int k = 0; k < 3; k ++)
                {
                    if (board[firstCell[i][0]+j][firstCell[i][1]+k] == '.') continue;
                    else 
                    {
                        if (m[board[firstCell[i][0]+j][firstCell[i][1]+k]] == 1) return false;
                        m[board[firstCell[i][0]+j][firstCell[i][1]+k]] ++; 
                    }
                }
            }
            for (auto it = m.begin(); it != m.end(); it ++) it->second = 0;
        }
        return true;
    }

};
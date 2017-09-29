class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
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
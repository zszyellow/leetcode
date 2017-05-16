class Solution {
public:
    int mLen, nLen;
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        mLen = board.size();
        nLen = board[0].size();
        for (int i = 0; i < mLen; i ++)
        {
            for (int j = 0; j < nLen; j ++)
            {
                update(board, i, j);
            }
        }
        for (int i = 0; i < mLen; i ++)
        {
            for (int j = 0; j < nLen; j ++)
            {
                if (board[i][j] == 2) board[i][j] = 1;
                if (board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
    
    void update(vector<vector<int>>& board, int m, int n)
    {
        int countLives = 0;
        for (int i = -1; i <= 1; i ++)
        {
            for (int j = -1; j <= 1; j ++)
            {
                if (i == j && i == 0) continue;
                if (m + i < 0 || m + i >= mLen || n + j < 0 || n + j >= nLen) continue;
                if (board[m+i][n+j] == 1 || board[m+i][n+j] == 3) countLives ++;
            }
        }
        if (board[m][n] == 1)
        {
            if (countLives < 2 || countLives > 3) board[m][n] = 3;
        }
        else 
        {
            if (countLives == 3) board[m][n] = 2;
        }
    }
};
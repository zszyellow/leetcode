class Solution {
public:
    int n;
    int h[9][10], v[9][10], b[9][10];
    void solveSudoku(vector<vector<char>>& board) 
    {
        n = board.size();
        // row, col & piece
        memset(h, 0, sizeof(h));
        memset(v, 0, sizeof(v));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (board[i][j] != '.') 
                {
                    h[i][board[i][j] - '0'] = 1;
                    v[j][board[i][j] - '0'] = 1;
                    b[i / 3 * 3 + j / 3][board[i][j] - '0'] = 1;
                }
            }
        }
        solve(0, 0, board);
    }
    
    bool solve(int i, int j, vector<vector<char>>& a) {
        if (i == n) return true;
        if (j == n) return solve(i + 1, 0, a);
        if (a[i][j] != '.') return solve(i, j + 1, a);
        for (int k = 1; k <= 9; k ++) {
            if (!h[i][k] && !v[j][k] && !b[i / 3 * 3 + j / 3][k]) 
            {
                a[i][j] = '0' + k;
                h[i][k] = 1; 
                v[j][k] = 1; 
                b[i / 3 * 3 + j / 3][k] = 1;
                if (solve(i, j + 1, a)) return true;
                h[i][k] = 0; 
                v[j][k] = 0; 
                b[i / 3 * 3 + j / 3][k] = 0;
                a[i][j] = '.';
            }
        }
        return false;
    }
};
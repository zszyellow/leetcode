class Solution {
public:
    int m;
    int n;

    void solve(vector<vector<char> >& board) {
        if (board.empty() || board[0].empty()) return;
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O')
                    DFS(board, i, j);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == ' ') board[i][j] = 'O';
            }
        }
    }
    void DFS(vector<vector<char> > &board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = ' ';
            if (i > 0 && board[i - 1][j] == 'O')
                DFS(board, i - 1, j);
            if (j < board[i].size() - 1 && board[i][j + 1] == 'O')
                DFS(board, i, j + 1);
            if (i < board.size() - 1 && board[i + 1][j] == 'O')
                DFS(board, i + 1, j);
            if (j > 1 && board[i][j - 1] == 'O')
                DFS(board, i, j - 1);
        }
    }
};

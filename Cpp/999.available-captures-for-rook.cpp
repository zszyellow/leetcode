class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        const int N = 8;
        vector<int> cord_rook;
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                if (board[i][j] == 'R') cord_rook = {i, j};
            }
        } 
            
        int res = 0;
        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto direction : directions) {
            int x = cord_rook[0] + direction[0], y = cord_rook[1] + direction[1];
            while (x >= 0 && x < N && y >= 0 && y < N) {
                if (board[x][y] == '.') {
                    x += direction[0];
                    y += direction[1];
                } else {
                    if (board[x][y] == 'p') res ++;
                    break; 
                }
            }
        }
        return res;
    }
};
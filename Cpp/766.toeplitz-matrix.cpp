class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         for (int i = 0; i < m; ++ i) {
//             for (int j = 0; j < n; ++j) {
//                 if (i > 0 && j > 0 && matrix[i][j] != matrix[i-1][j-1]) return false;
//             }
//         }
//         return true;
        
        int m = matrix.size(), n = matrix[0].size();
        bool res = true;
        for (int j = 0; j < n; ++ j) {
            int x = m-1, y = j, cur = matrix[x][y];
            res = res && checkDiagonal(matrix, cur, x, y);
        }
        
        for (int i = m-2; i >= 0; -- i) {
            int x = i, y = n - 1, cur = matrix[x][y];
            res = res && checkDiagonal(matrix, cur, x, y);
        }
        return res;
    }
    
    bool checkDiagonal(vector<vector<int>>& matrix, int cur, int x, int y) {
        while (x >= 0 && y >= 0) {
            if (matrix[x][y] != cur) return false;
            x --;
            y --;
        }
        return true;
    }
};
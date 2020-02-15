class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> columns;
        backtracking(n, 0, columns, result);
        return result;
    }
    
    void backtracking(int n, int cur_row, vector<int> &columns, int &result) {
        if (cur_row == n) {
            result ++;
            return;
        }
        for (int cur_col = 0; cur_col < n; cur_col ++) {
            columns.push_back(cur_col);
            if (isValid(columns, cur_row, cur_col)) {
                backtracking(n, cur_row+1, columns, result);
            }
            columns.pop_back();
        }
    }
    
    bool isValid(vector<int> &columns, int cur_row, int cur_col) {
        for (int i = 0; i < columns.size()-1; i ++) {
            if (columns[i] == cur_col ||
                abs(cur_row - i) == abs(cur_col - columns[i])) {
                return false;
            }
        }
        return true;
    }
};
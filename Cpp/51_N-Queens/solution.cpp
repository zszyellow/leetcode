class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result; // result vendor
        vector<string> cur_result; // current result
        vector<int> columns; // current collumns chosen
        backtracking(n, 0, columns, cur_result, result);
        return result;
    }

    void backtracking(int n,
                      int cur_row,
                      vector<int> &columns,
                      vector<string> &cur_result,
                      vector<vector<string>> &result) {
        if (cur_row == n) {
            result.push_back(cur_result);
            return;
        }
        for (int cur_column = 0; cur_column < n; cur_column ++) {
            string tmp_row(n, '.');
            tmp_row[cur_column] = 'Q';
            cur_result.push_back(tmp_row);
            columns.push_back(cur_column);
            if (isValid(columns, cur_row, cur_column)) {
                backtracking(n, cur_row+1, columns, cur_result, result);
            }
            cur_result.pop_back();
            columns.pop_back();
        }
    }

    bool isValid(vector<int> &columns,
                 int cur_row,
                 int cur_column) {
        for (int i = 0; i < columns.size()-1; i ++) {
            if (cur_column == columns[i] || 
                abs(cur_row - i) == abs(cur_column - columns[i])) {
                return false;
            }
        }
        return true;
    }

};
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> one_res;
        vector<int> col;
        traverse(n, 0, col, one_res, res);
        return res;
    }
    
    // traverse the chess board to find the possible result
    // Params:
    // n       ->   the number of rows of the chess board
    // cur_row ->   current row
    // col     ->   the col vector 
    // one_sol ->   one possible solution
    // res     ->   all solutions
    void traverse(int n, int cur_row, vector<int> &col, vector<string> &one_res, vector<vector<string>> &res) 
    {
        if (cur_row == n) 
        {
            res.push_back(one_res);
            return;
        }
        
        for (int cur_col = 0; cur_col < n; cur_col ++) 
        {
            if (valid(col, cur_row, cur_col)) 
            {
                string s(n, '.');
                s[cur_col] = 'Q';
                one_res.push_back(s);
                col.push_back(cur_col);
                traverse(n, cur_row + 1, col, one_res, res);
                one_res.pop_back();
                col.pop_back();
            }
        }
    }
    
    // check current position is valid or not
    // Params:
    // col     ->  the col vector
    // cur_row ->  current row
    // cur_col ->  current column
    bool valid(vector<int> &col, int cur_row, int cur_col) 
    {
        // check if it is in the same row
        if (cur_row < col.size()) return false;
        // check if it is in the same col or in the same diagonal
        for (int i = 0; i < col.size(); i ++) 
        {
            if (cur_col == col[i] || abs(cur_row-i) == abs(cur_col-col[i]))
                return false;
        }
        return true;
    }
};
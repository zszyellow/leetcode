class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> visited(n, false);
        
        for (int i = 0; i < m; ++ i) {
            int row_min = INT_MAX, col_idx = -1;
            for (int j = 0; j < n; ++ j) {
                if (visited[j]) continue;
                else if (row_min > matrix[i][j]) {
                    row_min = matrix[i][j];
                    col_idx = j;
                }
            }
            
            bool is_lucky = true;
            if (col_idx != -1) {
                for (int k = 0; k < m; ++ k) {
                    if (matrix[k][col_idx] > matrix[i][col_idx]) {
                        is_lucky = false;
                        break;
                    }
                } 
                 if (is_lucky) {
                    res.push_back(matrix[i][col_idx]);
                    visited[col_idx] = true;
                }
            }
        }
        
        return res;
    }
};
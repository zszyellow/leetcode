class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int last_row = -1;
        for (int i = 0; i < m; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (!matrix[i][j]) last_row = i;
            }
        }

        if (last_row == -1) return;
        for (int i = 0; i < last_row; i ++)
        {
            bool is_zero = false;
            for (int j = 0; j < n; j ++)
            {
                
                if (!matrix[i][j]) 
                {
                    is_zero = true;
                    matrix[last_row][j] = 0;
                }
            }
            if (is_zero)
                for (int j = 0; j < n; j ++) 
                    matrix[i][j] = 0;
        }
        for (int j = 0; j < n; j ++)
        {
            if (!matrix[last_row][j]) 
            {
                for (int i = 0; i < m; i ++) 
                    matrix[i][j] = 0;
            }
        }
        for (int j = 0; j < n; j ++) matrix[last_row][j] = 0;
    }
};
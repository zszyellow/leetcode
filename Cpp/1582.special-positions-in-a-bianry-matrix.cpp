class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row_sum(m, 0), col_sum(n, 0);
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                row_sum[i] += mat[i][j];
                col_sum[j] += mat[i][j];
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (mat[i][j] == 1 && row_sum[i] == 1 && col_sum[j] == 1) 
                    res ++;
            }
        }
        return res;
    }
};
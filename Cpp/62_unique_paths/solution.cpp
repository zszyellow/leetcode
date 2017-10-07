class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grids(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; i ++)
            for (int j = 1; j < n; j ++)
                grids[i][j] = grids[i-1][j] + grids[i][j-1];
        
        return grids[m-1][n-1];
    }
};
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        unordered_set<string> hash_set;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) {
                    string path = "";
                    dfs(grid, path, i, j, m, n, '0');
                    hash_set.insert(path);
                }
            }
        }
        return hash_set.size();
    }
 
    void dfs(vector<vector<int>> &grid, string &path, int r, int c, int m, int n, char d) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return;
        grid[r][c] = 0;
        path += d;
        dfs(grid, path, r-1, c, m, n, '1');
        dfs(grid, path, r+1, c, m, n, '2');
        dfs(grid, path, r, c-1, m, n, '3');
        dfs(grid, path, r, c+1, m, n, '4');
        path += '0';
    }
};
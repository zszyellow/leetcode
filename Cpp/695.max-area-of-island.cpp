class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int res = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                res = std::max(res, getArea(grid, visited, i, j));
            }
        }
        return res;
    }
    
    int getArea(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0) return 0;
        visited[i][j] = true;
        return 1 + getArea(grid, visited, i-1, j)
                 + getArea(grid, visited, i+1, j)
                 + getArea(grid, visited, i, j-1)
                 + getArea(grid, visited, i, j+1);
    }
};
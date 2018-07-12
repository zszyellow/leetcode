class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                res = max(res, getArea(i, j, grid, visited));
            }
        }
        return res;
    }
    
    int getArea(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0) return 0;
        visited[i][j] = true;
        return 1 + getArea(i-1,j,grid,visited) + getArea(i+1,j,grid,visited) + getArea(i,j-1,grid,visited) + getArea(i,j+1,grid,visited);
    }
};
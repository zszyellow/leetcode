class Solution 
{
private:
    int row;
    int col;
    void dfs(vector<vector<char>>& grid, int crow, int ccol)
    {
        if (crow < 0 || ccol < 0 || crow >= this->row || ccol >= this->col || grid[crow][ccol] != '1') return;
        grid[crow][ccol] = '0';
        dfs(grid, crow+1, ccol);
        dfs(grid, crow-1, ccol);
        dfs(grid, crow, ccol+1);
        dfs(grid, crow, ccol-1);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty() || grid[0].empty()) return 0;
        this->row = grid.size();
        this->col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row; i ++)
        {
            for (int j = 0; j < col; j ++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    res ++;
                }
            }
        }
        return res;
    }
    
};
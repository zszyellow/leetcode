/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
private:
    int num_no = 0;
    int m;
    int n;
    pair<int, int> start_pos;
    pair<int, int> end_pos;
    vector<vector<int>> directions{{1,0}, {0,1}, {-1,0}, {0, -1}};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res = 0;
        int cur_num = 0;
        m = grid.size();
        n = grid[0].size();
        
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    start_pos.first = i;
                    start_pos.second = j;
                } else if (grid[i][j] == 2) {
                    end_pos.first = i;
                    end_pos.second = j;
                } else if (grid[i][j] == 0) {
                    num_no ++;
                }
            }
        }
        
        dfs(grid, start_pos.first, start_pos.second, cur_num, res);
        return res;
    }
    
    void dfs(vector<vector<int>>& grid,
             int cur_i,
             int cur_j,
             int& cur_num,
             int& res) {
        if (cur_i == end_pos.first && cur_j == end_pos.second) {
            if (cur_num == num_no) res ++;
            return;
        }
        if (cur_i == start_pos.first && cur_j == start_pos.second) {
            for (auto direction : directions) {
                int i = cur_i + direction[0];
                int j = cur_j + direction[1];
                if (validMove(i, j, grid)) {
                    dfs(grid, i, j, cur_num, res);
                }
            }
        } else {
            for (auto direction : directions) {
                int i = cur_i + direction[0];
                int j = cur_j + direction[1];
                if (validMove(i, j, grid)) {
                    grid[cur_i][cur_j] = -1;
                    cur_num ++;
                    dfs(grid, i, j, cur_num, res);
                    grid[cur_i][cur_j] = 0;
                    cur_num --;
                }
            }
        }
    }
    
    bool validMove(int i, int j, vector<vector<int>>& grid) {
        if (i >= 0 && i < m && j >= 0 && j < n && (grid[i][j] == 0 || grid[i][j] == 2))
            return true;
        return false;
    }
};
// @lc code=end


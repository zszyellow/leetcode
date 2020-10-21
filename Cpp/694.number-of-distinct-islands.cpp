class Solution {
public:
    /* Using path as key, TC: O(M*N) SC: O(M*N) */
//     int numDistinctIslands(vector<vector<int>>& grid) {
//         if (grid.empty() || grid[0].empty()) return 0;
//         int m = grid.size(), n = grid[0].size();
//         unordered_set<string> hash_set;
        
//         for (int i = 0; i < m; ++ i) {
//             for (int j = 0; j < n; ++ j) {
//                 if (grid[i][j] == 1) {
//                     string path = "";
//                     dfs(grid, path, i, j, m, n, '0');
//                     hash_set.insert(path);
//                 }
//             }
//         }
//         return hash_set.size();
//     }
 
//     void dfs(vector<vector<int>> &grid, string &path, int r, int c, int m, int n, char d) {
//         if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return;
//         grid[r][c] = 0;
//         path += d;
//         dfs(grid, path, r-1, c, m, n, '1');
//         dfs(grid, path, r+1, c, m, n, '2');
//         dfs(grid, path, r, c-1, m, n, '3');
//         dfs(grid, path, r, c+1, m, n, '4');
//         path += '0';
//     }
    
    /* Using shape as key, TC: O(M*N), SC: O(M*N) */
     int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> shape_set;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(grid, shape, i, j, m, n);
                    shape_set.insert(norm(shape));
                }
            }
        }
        return shape_set.size();
    }
    
    void dfs(vector<vector<int>> &grid, vector<pair<int, int>> &shape, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return;
        grid[r][c] = 0;
        shape.push_back(make_pair(r, c));
        dfs(grid, shape, r-1, c, m, n);
        dfs(grid, shape, r+1, c, m, n);
        dfs(grid, shape, r, c-1, m, n);
        dfs(grid, shape, r, c+1, m, n);
    }
    
    vector<pair<int, int>> norm(vector<pair<int, int>> &shape) {
        auto left_top = *min_element(shape.begin(), shape.end());
        for (auto &&[x, y] : shape) {
            x -= left_top.first;
            y -= left_top.second;
        } 
        return shape;
    }
};
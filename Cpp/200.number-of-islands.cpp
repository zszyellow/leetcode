class Solution {
public:
    /**
     * DFS with Recursion
     * TC: O(M*N)
     * SC: O(M*N)
     */
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty() || grid[0].empty()) return 0;
//         int m = grid.size(), n = grid[0].size();
//         int res = 0;
//         for (int i = 0; i < m; ++ i) {
//             for (int j = 0; j < n; ++ j) {
//                 if (grid[i][j] == '1') {
//                     dfs(grid, i, j, m, n);
//                     res ++;
//                 }
//             }
//         }
//         return res;
//     }
    
//     void dfs(vector<vector<char>> &grid, int r, int c, int m, int n) {
//         if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') return;
//         grid[r][c] = '0';
//         dfs(grid, r-1, c, m, n);
//         dfs(grid, r+1, c, m, n);
//         dfs(grid, r, c-1, m, n);
//         dfs(grid, r, c+1, m, n);
//     }
    
    /**
     * DFS with Recursion
     * TC: O(M*N)
     * SC: O(M*N)
     */
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        stack<pair<int, int>> st;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == '1') {
                    st.push(make_pair(i, j));
                    
                    while (!st.empty()) {
                        int r = st.top().first, c = st.top().second;
                        grid[r][c] = '0';
                        st.pop();
                        
                        for (auto &&[dr, dc] : directions) {
                            int r1 = r + dr, c1 = c + dc;
                            if (r1 >= 0 && r1 < m && c1 >= 0 && c1 < n && grid[r1][c1] == '1')
                                st.push(make_pair(r1, c1));
                        }
                    }
                    res ++;
                }
            }
        }
        return res;
    }
};
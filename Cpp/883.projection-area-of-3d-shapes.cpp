class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int N = grid.size(), xy = 0, xz = 0, yz = 0;
        vector<int> y_max(N, 0);
        for (int i = 0; i < N; ++ i) {
            int x_max = 0;
            for (int j = 0; j < N; ++ j) {
                xy += (grid[i][j] != 0);
                x_max = std::max(x_max, grid[i][j]);
                y_max[j] = std::max(y_max[j], grid[i][j]);
            }
            xz += x_max;
        }
        yz = std::accumulate(y_max.begin(), y_max.end(), yz);
        return xy + xz + yz;
    }
};
class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &g, vector<pair<int, int>> &shape) {
        if (r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c] == 0) return;
        g[r][c] = 0;
        shape.push_back({r,c});
        dfs(r+1, c, g, shape);
        dfs(r-1, c, g, shape);
        dfs(r, c+1, g, shape);
        dfs(r, c-1, g, shape);
    }
    
    vector<pair<int,int>> norm(vector<pair<int,int>>& shape) {
        vector<vector<pair<int,int>>> s(8);
        
        // compute rotations/reflections.
        for (auto cord : shape) {
            int x = cord.first, y = cord.second;
            s[0].push_back({x, y});
            s[1].push_back({x, -y});
            s[2].push_back({-x, y});
            s[3].push_back({-x, -y});
            s[4].push_back({y, -x});
            s[5].push_back({-y, x});
            s[6].push_back({-y, -x});
            s[7].push_back({y, x});
        }
        
        for (auto &l : s) std::sort(l.begin(), l.end());
        for (auto &l : s) {
            int x = l[0].first, y = l[0].second;
            for (int i = 0; i < shape.size(); ++ i) {
                l[i] = {l[i].first - x, l[i].second - y};
            }
        }
        return *min_element(s.begin(), s.end());
    }
    
    int numDistinctIslands2(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        
        set<vector<pair<int, int>>> s;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[i].size(); ++ j) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, grid, shape);
                    s.insert(norm(shape));
                }
            }
        }
        
        return s.size();
    }
};
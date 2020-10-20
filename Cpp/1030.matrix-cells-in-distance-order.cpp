class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        /* sort, TC: O(RClogRC), SC: O(RC) */
        vector<vector<int>> res;
        for (int i = 0; i < R; ++ i) 
            for (int j = 0; j < C; ++ j) 
                res.push_back({i, j});
        
        auto distance = [=](vector<int> &cord) -> int {
            return abs(cord[0] - r0) + abs(cord[1] - c0);
        };
        std::sort(res.begin(), res.end(), [=](vector<int> &A, vector<int> &B) -> bool {
            int dist_A = distance(A), dist_B = distance(B);
            return dist_A < dist_B;
        });
        
        return res;
        
        
        /* BFS, TC: O(R*C), SC: O(R*C) */
//         vector<vector<int>> res;
//         vector<vector<bool>> visited(R, vector<bool>(C, false));
//         vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//         queue<vector<int>> q;
//         q.push({r0, c0});
//         visited[r0][c0] = true;
        
//         while (!q.empty()) {
//             auto coordinate = q.front();
//             int x = coordinate[0], y = coordinate[1];
//             res.push_back({x, y});
//             q.pop();
            
//             for (auto direction : directions) {
//                 int x1 = x + direction[0], y1 = y + direction[1];
//                 if (x1 >= 0 && x1 < R && y1 >= 0 && y1 < C && !visited[x1][y1]) {
//                     q.push({x1, y1});
//                     visited[x1][y1] = true;
//                 }
//             }
//         }
//         return res;
    }
};
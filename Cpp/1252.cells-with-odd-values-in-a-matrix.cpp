class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);
        
        for (const auto& indice : indices) {
            rows[indice[0]] = !rows[indice[0]];
            cols[indice[1]] = !cols[indice[1]];
        }
        
        int r = 0, c = 0;
        for (bool row : rows) r += row;
        for (bool col : cols) c += col;
        
        return r*m + c*n - 2*r*c;
    }
};
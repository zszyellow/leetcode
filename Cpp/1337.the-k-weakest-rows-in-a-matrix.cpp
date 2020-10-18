class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        vector<bool> visited(m, false);
        
        for (int j = 0; j < n; ++ j) {
            for (int i = 0; i < m; ++ i) {
                if (!visited[i]) {
                    if (mat[i][j] == 0) {
                        res.push_back(i);
                        if (res.size() == k) return res;
                        visited[i] = true;
                    }   
                }
            }            
        }
        
        if (res.size() < k) {
            for (int i = 0; i < m; ++ i) {
                if (!visited[i]) res.push_back(i);
                if (res.size() == k) return res;   
            }
        }
                
        return res;
    }
};
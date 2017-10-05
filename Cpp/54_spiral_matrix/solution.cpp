class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        
        int m = matrix.size();
        int n = matrix[0].size();
        // top
        for (int i = 0; i < n; i ++) res.push_back(matrix[0][i]);
        // right
        for (int i = 1; i < m; i ++) res.push_back(matrix[i][n-1]);
        // bottom
        if (m > 1)
        {
            for (int i = n-2; i >= 0; i --) res.push_back(matrix[m-1][i]);   
        }
        // left
        if (n > 1)
        {
            for (int i = m-2; i > 0; i --) res.push_back(matrix[i][0]);
        }
        
        // recursive
        if (m > 2 && n > 2) 
        {
            vector<vector<int>> temp(matrix.begin()+1, matrix.begin()+m-1);
            for (int i = 0; i < m-2; i ++)
            {
                vector<int> temp2(temp[i].begin()+1, temp[i].begin()+n-1);
                temp[i] = temp2;
            }
            vector<int> rest(spiralOrder(temp));
            res.insert(res.end(), rest.begin(), rest.end());
        }
        
        return res;
    }
    
};
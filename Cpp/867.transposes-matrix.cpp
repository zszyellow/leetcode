class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<vector<int>> res(N, vector<int>(M, 0));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};
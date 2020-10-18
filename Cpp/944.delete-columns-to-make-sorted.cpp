class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n = A[0].size(), res = 0;
        if (m <= 1 || n < 1) return res;
        for (int j = 0; j < n; ++ j) {
            char cur = A[0][j];
            for (int i = 1; i < m; ++ i) {
                if (A[i][j] < cur) {
                    res ++;
                    break;
                } else {
                    cur = A[i][j];
                }
            }
        }
        return res;
    }
};
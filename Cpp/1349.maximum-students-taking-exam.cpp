class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        /* DP with bitmasking, TC: O(M*(2^2N) + M*N), SC: O(M*(2^N)) */
        int m = seats.size(), n = seats[0].size();
        vector<int> validity(m, 0);
        
        // compute validity for every row in current seats
        for (int i = 0; i < m; ++ i) {
            int cur = 0;
            for (int j = 0; j < n; ++ j) {
                cur = cur * 2 + (seats[i][j] == '.');
            }
            validity[i] = cur;    
        }
        
        // dp[i][mask]: first i-1 rows student number
        vector<vector<int>> dp(m+1, vector<int>(1 << n, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++ i) {
            int valid = validity[i-1];
            for (int j = 0; j < (1 << n); ++ j) {
                if ((j & valid) == j && (j & (j >> 1)) == 0) {
                    for (int k = 0; k < (1 << n); ++ k) {
                        if (dp[i-1][k] != -1 && (j & (k >> 1)) == 0 && ((j >> 1) & k) == 0) {
                            dp[i][j] = max(dp[i][j], dp[i-1][k] + __builtin_popcount(j));
                        }
                    }
                }
            }
        }
        
        return *max_element(dp[m].begin(), dp[m].end());
    }
};

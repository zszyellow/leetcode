class Solution {
public:
    bool isMatch(string s, string p) {
        /* Recurstion, TC&SC: exponential */
        // if (p.empty()) return s.empty();
        // else if (p.size() == 1 || p[1] != '*') {
        //     if (s.empty() || (p[0] != '.' && s[0] != p[0])) return false;
        //     return isMatch(s.substr(1), p.substr(1));
        // }
        // else {
        //     while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
        //         if (isMatch(s, p.substr(2))) return true;
        //         s = s.substr(1);
        //     }
        //     return isMatch(s, p.substr(2));
        // }
        
        /* DP, TC: O(MN), SC: O(MN) */
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;
        
        for (int i = m; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                bool first_match = (i < m && (s[i] == p[j] || p[j] == '.'));
                if (j+1 < n && p[j+1] == '*')
                    dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
                else 
                    dp[i][j] = first_match && dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};

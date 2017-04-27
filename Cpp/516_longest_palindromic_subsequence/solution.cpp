class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> m(s.size(), vector<int>(s.size()));
        for (int i = m.size()-1; i >= 0; i --)
        {
            m[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j]) m[i][j] = m[i+1][j-1] + 2;
                else m[i][j] = m[i+1][j] > m[i][j-1] ? m[i+1][j] : m[i][j-1];
            }
        }
        return m[0][s.size()-1];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        map<string, int> m;
        
        dp[0] = true;
        for (string val : wordDict) m[val] = 1;
        for (int i = 1; i <= s.size(); ++ i)
        {
            for (int j = 0; j < i; ++ j)
            {
                if (dp[j] && m.find(s.substr(j, i-j)) != m.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};
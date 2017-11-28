class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int len = prices.size();
        int res = 0;
        
        if (k >= len/2)
        {
            for (int i = 1; i < len; i ++)
                if (prices[i] > prices[i-1])
                    res = res + prices[i] - prices[i-1];
            return res;
        }
        else
        {
            vector<vector<int>> dp(k+1, vector<int>(len, 0));
            for (int i = 1; i <= k; i ++)
            {
                int tmp = -prices[0];
                for (int j = 0; j < len; j ++)
                {
                    dp[i][j] = std::max(dp[i][j-1], prices[j] + tmp);
                    tmp = std::max(tmp, dp[i-1][j-1]-prices[j]);
                }
            }
            return dp[k][len-1];
        }
    }
};
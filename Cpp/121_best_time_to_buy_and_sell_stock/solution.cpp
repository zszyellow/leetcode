class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCur = 0;
        int maxSofar = 0;
        for (int i = 1; i < prices.size(); i ++)
        {
            maxCur = std::max(0, maxCur += prices[i]-prices[i-1]);
            maxSofar = std::max(maxCur, maxSofar);
        }
        return maxSofar;
    }
};
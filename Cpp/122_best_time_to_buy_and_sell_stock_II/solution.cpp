#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int len = prices.size();
        if (len == 0) return 0;
        int res = 0, pre = prices[0];

        for (auto cur : prices)
        {
            if (cur > pre) res += cur - pre;
            pre = cur;
        }
        return res;
    }
};


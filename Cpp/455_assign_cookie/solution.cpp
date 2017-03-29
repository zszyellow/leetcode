class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        if (g.size() == 0 || s.size() == 0) return 0;
        sort(g.begin(), g.end(), [](int a, int b)
        {
            return a > b;
        });
        sort(s.begin(), s.end(), [](int a, int b)
        {
            return a > b;
        });

        int res = 0;
        auto it = s.begin();
        for (auto greed : g)
        {
            if (*it >= greed)
            {
                res ++;
                it ++;
            }
            if (it == s.end())
                break;
        }
        return res;
    }
};

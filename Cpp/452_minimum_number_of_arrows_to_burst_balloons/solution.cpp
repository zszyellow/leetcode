#include <iostream>
#include <vector>
#include <pair>

class Solution
{
public:
    int findMinArrowShots(vector<pair<int, int>>& points)
    {
        if (points.size() == 0) return 0;

        int res = 1;
        std::sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.second < b.second;
        });
        int terminal = points[0].second;

        for (auto point : points)
        {
            if (point.first > terminal)
            {
                terminal = point.second;
                res ++;
            }
        }

        return res;
    }
};


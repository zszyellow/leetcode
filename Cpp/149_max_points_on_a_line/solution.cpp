/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution 
{
public:
    int GCD(int a, int b)
    {
        if (!b) return a;
        return GCD(b, a%b);
    }
    
    int maxPoints(vector<Point>& points) 
    {
        int res(0);
        for (int i = 0; i < points.size(); ++ i)
        {
            int num_of_same(1);
            int max_num(0);
            int vertical(0);
            map<pair<int, int>, int> hashmap;
            for (int j = i + 1; j < points.size(); j ++)
            {
                if (points[i].x == points[j].x && points[i].y == points[j].y) num_of_same ++;
                else if (points[i].x == points[j].x) vertical ++;
                else 
                {
                    int a(points[i].x - points[j].x);
                    int b(points[i].y - points[j].y);
                    int gcd(GCD(a, b));
                    a /= gcd;
                    b /= gcd;
                    hashmap[make_pair(a, b)] ++;
                }
            }
            for (auto mpair : hashmap) max_num = std::max(max_num, mpair.second);
            max_num = std::max(max_num, vertical);
            max_num += num_of_same;
            res = std::max(max_num, res);
        }
        return res;
    }
};
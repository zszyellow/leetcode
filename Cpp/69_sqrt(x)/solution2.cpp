class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double pre = 0.0, cur = 1.0;
        while (abs(cur - pre) > 0.1)
        {
            pre = cur;
            cur = pre / 2.0 + x / (2.0 * pre);
        }
        return (int)cur;
    }
};

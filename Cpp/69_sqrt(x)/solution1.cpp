class Solution {
public:
    int mySqrt(int x) {
        unsigned long long b = 0, t = x;
        unsigned long long mid = (t + b) / 2;
        while (t > b)
        {
            if (mid * mid == x) break;
            if (mid * mid > x)
            {
                t = mid - 1;
                mid = (t + b) / 2;
            }
            else
            {
                b = mid + 1;
                mid = (t + b) / 2;
            }
        }
        if (mid * mid > x) mid --;
        return mid;
    }
};
